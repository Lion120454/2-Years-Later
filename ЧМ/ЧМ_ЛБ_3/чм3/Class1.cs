using System;
using System.Collections;
using System.Data;
using System.IO;
using System.Linq;
using System.Net.WebSockets;
using PolStrLib;

namespace чм_3
{
    class Matrix : IEnumerable, IFormattable, ICloneable
    {
        private double[] data;
        private uint lines;
        private uint columns;
        private static uint newID = 0;
        private uint id;
        public double[] Data 
        { 
            get 
            { 
                return data; 
            }
            private set
            {
                data = value; 
            } 
        }
        public uint Lines 
        { 
            get 
            { 
                return lines;
            } 
            private set 
            { 
                lines = value; 
            } 
        }
        public uint Columns 
        { 
            get 
            { 
                return columns;
            } 
            private set 
            {
                columns = value;
            } 
        }
        //Конструктор по умолчанию
        public Matrix(uint _lines = 3, uint _columns = 3, double[] _data = null)
        {
            if ((_lines == 0) || (_columns == 0))
            {
                throw new ArgumentException("Количество строк и колонок должно быть отлично от 0");
            }
            if ((_data != null) && (_lines * _columns > _data.Length))
            {
                throw new ArgumentException("Данных не достаточно для полного заполнения матрицы");
            }
            if ((_data != null) && (_lines * _columns < _data.Length))
            {
                throw new ArgumentException("Выход за пределы размеров матрицы");
            }
            id = newID++;
            lines = _lines;
            columns = _columns;
            data = new double[lines * columns];
            if (_data != null)
            {
                _data.CopyTo(data, 0);
            }
            else
            {
                for (int i = 0; i < columns * lines; i++)
                {
                    data[i] = 0;
                }
            }
        }
        //Конструктор квадратной матрицы
        public Matrix(uint _size, double[] _data) : this(_size, _size, _data)
        {
        }
        //Конструктор копирования
        public Matrix(Matrix _matrix) : this(_matrix.lines, _matrix.columns, _matrix.data)
        {
        }



        //Единичная матрица
        public Matrix UnitMatrix()
        {
            double[] unit = new double[lines * lines];
            for (uint i = 0; i < lines; i++)
            {
                unit[i * lines + i] = 1.0;
            }
            Matrix answ = new Matrix(lines, lines, unit);
            return answ;
        }
        //Найти M
        private Matrix MatrixM(uint _k, bool _inv, Matrix _a)
        {
            Matrix _M = new Matrix(lines, lines);
            --_k;
            if (_inv)
            {
                for (uint i = 0; i < lines; i++)
                {
                    for (uint j = 0; j < lines; j++)
                    {
                        if (i == _k)
                        {
                            _M[i, j] = _a[i + 1, j];
                            continue;
                        }
                        if (i == j)
                        {
                            _M[i, j] = 1;
                            continue;
                        }
                        _M[i, j] = 0;
                    }
                }
            }
            else
            {
                for (uint i = 0; i < lines; i++)
                {
                    for (uint j = 0; j < lines; j++)
                    {
                        if ((i == _k) && (j == _k))
                        {
                            _M[i, j] = 1 / _a[_k + 1, _k];

                            continue;
                        }
                        if (i == _k)
                        {
                            _M[i, j] = -(_a[_k + 1, j] / _a[_k + 1, _k]);

                            continue;
                        }
                        if (i == j)
                        {
                            _M[i, j] = 1;

                            continue;
                        }
                        _M[i, j] = 0;
                    }
                }
            }
            return _M;
        }
        //Найти S
        private Matrix[] MatrixS()
        {
            Matrix[] a = new Matrix[lines];
            a[0] = this.Clone();
            Matrix[,] m = new Matrix[lines - 1, 2];
            for (uint i = 1; i < lines; i++)
            {
                m[i - 1, 0] = MatrixM(lines - i, false, a[i - 1]);
                m[i - 1, 1] = MatrixM(lines - i, true, a[i - 1]);
                a[i] = m[i - 1, 1] * a[i - 1] * m[i - 1, 0];
            }
            Matrix[] _S = new Matrix[2];
            _S[0] = m[0, 0];
            _S[1] = m[lines - 2, 1];
            for (uint i = 1; i < lines - 1; i++)
            {
                _S[0] *= m[i, 0];
                _S[1] *= m[lines - 2 - i, 1];
            }
            return _S;
        }
        //Матрица фробениуса
        public Matrix MatrixFrob()
        {
            Matrix[] s = MatrixS();
            Matrix p = s[1] * this * s[0];
            return p;
        }

        //Решение полинома
        private static double[,] Polinom(double[] _values, double _start = -10, double _end = 10, double _disp = 0.001, double _step = 0.0001)
        {
            string polinom;
            string fx = GetPolinom(_values);
            PolStr.StrToPolStr(fx, out polinom, 0);
            double[,] answ = new double[_values.Count(), 2];
            bool wasFound = false;
            double x0 = 0;
            double f0 = PolStr.EvalPolStr(polinom, x0, 0);
            f0 = _values.Count() % 2 == 0 ? f0 : -f0;
            double f1 = f0;
            uint counter = 0;

            for (double x1 = _start; (counter < _values.Count()) || (x1 < _end); x1 += _step)
            {
                f0 = f1;
                f1 = PolStr.EvalPolStr(polinom, x1, 0);
                f1 = _values.Count() % 2 == 0 ? f1 : -f1;
                if ((Math.Abs(f1) <= _disp) && (Math.Abs(f1) < Math.Abs(f0)))
                {
                    x0 = x1;
                    wasFound = true;
                    continue;
                }
                if (wasFound || ((f0 * f1) < 0))
                {
                    wasFound = false;
                    uint multiplicity = 1;
                    answ[counter, 0] = x0;
                    double tempDisp = _disp;
                    while (Math.Abs(PolStr.EvalPolStr(polinom, x0, multiplicity)) < tempDisp)
                    {
                        ++multiplicity;
                        tempDisp *= 10;
                    }
                    for (uint i = 0; i < (multiplicity - 1); i++)
                    {
                        answ[counter, 1] = multiplicity;
                        answ[++counter, 0] = x0;
                    }
                    answ[counter++, 1] = multiplicity;
                }
            }
            return answ;
        }
        
        //Собственные числа
        public double[,] EigenVal(in StreamWriter _writer = null)
        {
            double[] values = new double[lines];
            Matrix p = this.MatrixFrob();
            if (_writer != null)
            {
                _writer.WriteLine("Матрица Фробениуса:");
                _writer.WriteLine(p);
            }
            for (uint i = 0; i < lines; i++)
            {
                values[i] = p[0, i];
            }
            return Polinom(values);
        }
        public double CheckEigen(double _eigen)
        {
            Matrix tempMat = this - this.UnitMatrix() * _eigen;
            return tempMat.Det();
        }

        //Собственные вектора
        public Matrix EigenVector(double _eigen)
        {
            Matrix y = new Matrix(lines, 1);
            for (uint i = 0; i < lines; i++)
            {
                y[i, 0] = Math.Round(Math.Pow(_eigen, lines - i - 1),3);
            }
            return MatrixS()[0] * y;
        }
        public Matrix CheckEigenVector(Matrix _vector, double _eigen)
        {
            return (this * _vector) - (_vector * _eigen);
        }























        //Определитель матрицы
        public double Det()
        {
            Matrix copy = this.Clone();
            double det = 1;
            for (uint i = 0; i < lines; i++)
            {
                double cof = copy[i, i];
                det *= cof;
                for (uint j = i; j < lines; j++)
                {
                    copy[i, j] /= cof;
                }
                for (uint j = i + 1; j < lines; j++)
                {
                    cof = copy[j, i];
                    for (uint k = i; k < lines; k++)
                    {
                        copy[j, k] -= cof * copy[i, k];
                    }
                }
            }
            return det;
        }
        //Получить полином в строке
        private static string GetPolinom(double[] values)
        {
            string f = "";
            for (uint i = 0; i < values.Count() + 1; i++)
            {
                if (i != 0)
                {
                    double buf = values[i - 1] * -1;
                    if (!(buf < 0))
                    {
                        f += "+";
                    }
                    f += buf;
                    if (i != values.Count())
                    {
                        f += "*";
                    }
                }
                for (uint j = 0; j < values.Count() - i; j++)
                {
                    f += "x";
                    if (j == values.Count() - i - 1)
                    {
                        break;
                    }
                    f += "*";
                }
            }
            return f.Replace(',', '.');
        }
        //Проверка умножения
        public bool CheckMul(Matrix _operand)
        {
            if (_operand == null)
            {
                throw new ArgumentException("Операнд не инициализрован");
            }

            if (columns == _operand.lines)
            {
                return true;
            }
            return false;
        }
        //Проверка сложения
        public bool CheckAdd(Matrix _operand)
        {
            if (_operand == null)
            {
                throw new ArgumentException("Операнд не инициализрован");
            }

            if ((columns == _operand.columns) && (lines == _operand.lines))
            {
                return true;
            }
            return false;
        }
        //Оператор умножения (матрица, матрица)
        public static Matrix operator *(Matrix _operand1, Matrix _operand2)
        {
            if (!_operand1.CheckMul(_operand2))
            {
                throw new ArgumentException("Данные матрицы нельзя перемножать");
            }

            double[] newData = new double[_operand1.lines * _operand2.columns];
            for (int i = 0; i < _operand1.lines; i++)
            {
                for (int j = 0; j < _operand2.columns; j++)
                {
                    newData[i * _operand2.columns + j] = 0;
                    for (int k = 0; k < _operand1.columns; k++)
                    {
                        newData[i * _operand2.columns + j] += (_operand1.data[i * _operand1.columns + k] * _operand2.data[k * _operand2.columns + j]);
                    }
                }
            }

            Matrix toOut = new Matrix(_operand1.lines, _operand2.columns, newData);

            return toOut;
        }
        //Оператор умножения (матрица, скаляр)
        public static Matrix operator *(Matrix _operand1, double _operand2)
        {
            double[] newData = new double[_operand1.lines * _operand1.columns];

            _operand1.data.CopyTo(newData, 0);

            for (int i = 0; i < (_operand1.columns * _operand1.lines); i++)
            {
                newData[i] *= _operand2;
            }

            Matrix toOut = new Matrix(_operand1.lines, _operand1.columns, newData);

            return toOut;
        }
        //Оператор сложения (матрица, матрица)
        public static Matrix operator +(Matrix _operand1, Matrix _operand2)
        {
            if (!_operand1.CheckAdd(_operand2))
            {
                throw new ArgumentException("Данные матрицы нельзя складывать");
            }

            double[] newData = new double[_operand1.lines * _operand1.columns];

            _operand1.data.CopyTo(newData, 0);

            for (int i = 0; i < _operand1.lines * _operand1.columns; i++)
            {
                newData[i] += _operand2.data[i];
            }

            Matrix toOut = new Matrix(_operand1.lines, _operand1.columns, newData);

            return toOut;
        }
        //Оператор вычитания (матрица, матрица)
        public static Matrix operator -(Matrix _operand1, Matrix _operand2)
        {
            if (!_operand1.CheckAdd(_operand2))
            {
                throw new ArgumentException("Данные матрицы нельзя вычитать");
            }

            double[] newData = new double[_operand1.lines * _operand1.columns];

            _operand1.data.CopyTo(newData, 0);

            for (int i = 0; i < _operand1.lines * _operand1.columns; i++)
            {
                newData[i] -= _operand2.data[i];
            }

            Matrix toOut = new Matrix(_operand1.lines, _operand1.columns, newData);

            return toOut;
        }
        //Индексатор
        public double this[uint i, uint j]
        {
            get { return data[i * columns + j]; }
            set { data[i * columns + j] = value; }
        }
        //Перевод в строку
        public override string ToString()
        {
            string toOut = "";
            for (int i = 0; i < lines; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    toOut += data[i * columns + j].ToString();
                    toOut += " ";
                }
                toOut += "\n";
            }
            return toOut;
        }
        //Интерфейс клонирования
        object ICloneable.Clone()
        {
            return Clone();
        }
        public Matrix Clone()
        {
            Matrix toOut = new Matrix(this.lines, this.columns, this.data);

            return toOut;
        }
        //Интерфейс форматирования
        string IFormattable.ToString(string format, IFormatProvider formatProvider)
        {
            string toOut = "";
            for (int i = 0; i < lines; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    toOut += data[i * columns + j].ToString();
                    toOut += " ";
                }
                toOut += "\n";
            }
            return toOut;
        }
        //Интерфейс перечисления
        IEnumerator IEnumerable.GetEnumerator()
        {
            return data.GetEnumerator();
        }
    };
}