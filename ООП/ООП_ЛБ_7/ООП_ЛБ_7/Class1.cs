using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ООП_ЛБ_7
{
    class Matrix:ICloneable, IFormattable; //IEnumerable<int>
    {
        public double[] dateMatrix;//Данные мытрицы
        private int MatrixID;//ID матрицы
        static int countMatrix = 1;//Колличество матриц


        public Matrix()//Конструктор Матрицы по умолчанию
        {
            MatrixID = countMatrix++;
            Console.WriteLine("++Конструктор 1 ID {0}++", MatrixID);
            dateMatrix = null;
            Console.WriteLine("++             ++");
        }
        public Matrix(double[] _dateMatrix)//Конструктор Матрицы по двухмерному массиву
        {
            MatrixID = countMatrix++;
            Console.WriteLine("++Конструктор 2 ID {0}++", MatrixID);
            dateMatrix = new double[_dateMatrix.GetLength(0)+ _dateMatrix.GetLength(1)];

            int k = 0;
            for (int i = 0; i < _dateMatrix.GetLength(0); i++)
            {
                dateMatrix[k] = _dateMatrix[i];
                k++;
                Console.Write("   {0}", dateMatrix[i]);
            }
            Console.WriteLine("++             ++");
        }
        public Matrix(Matrix _matrix)// Конструктор копирование Матрицы
        {
            MatrixID = countMatrix++;
            Console.WriteLine("++Конструктор 5 ID {0}++", MatrixID);
            dateMatrix = new double[_matrix.dateMatrix.GetLength(0)+ _matrix.dateMatrix.GetLength(1)];

            for (int i = 0; i < _matrix.dateMatrix.GetLength(0); i++)
            {
                dateMatrix[i] = _matrix.dateMatrix[i];
                Console.Write("   {0}", dateMatrix[i]);
            }
            Console.WriteLine("++             ++");
        }

        public static bool Check_Plus_Matrix(Matrix _matrix1, Matrix _matrix2)//Метод проверки возможности сложения двух матриц
        {
            return (_matrix1.dateMatrix.GetLength(1) == _matrix2.dateMatrix.GetLength(1)) && (_matrix1.dateMatrix.GetLength(0) == _matrix2.dateMatrix.GetLength(0));
        }
        public static bool Check_Mul_Matrix(Matrix _matrix1, Matrix _matrix2)//Метод проверки возможности умножения двух матриц
        {
            return (_matrix1.dateMatrix.GetLength(1) == _matrix2.dateMatrix.GetLength(0));
        }
        public double Max_Matrix()//Метод поиска максимального элемента Матрицы*
        {
            double max = 0;
            for (int i = 0; i < dateMatrix.GetLength(0); i++)
            {
                if (max < dateMatrix[i])
                {
                    max = dateMatrix[i];
                }
            }
            return max;
        }
        public double Min_Matrix()//Метод поиска минимального элемента Матрицы*
        {
            double min = Max_Matrix();
            for (int i = 0; i < dateMatrix.GetLength(0); i++)
            {
                if (min > dateMatrix[i])
                {
                    min = dateMatrix[i];
                }
            }
            return min;
        }
        public static Matrix operator +(Matrix _matrix1, Matrix _matrix2)//Переопределение оператора + Матриц*
        {
            Matrix New = new Matrix(_matrix1);
            if (!Check_Plus_Matrix(New, _matrix2))
            {
                throw new ArgumentException("++    ERROR    ++");
            }
            else
            {
                for (int i = 0; i < New.dateMatrix.GetLength(0); i++)
                {
                    New.dateMatrix[i] += _matrix2.dateMatrix[i];
                }
                return New;
            }
        }
        public static Matrix operator -(Matrix _matrix1, Matrix _matrix2)//Переопределение оператора - Матриц*
        {
            Matrix New = new Matrix(_matrix1);
            if (!Check_Plus_Matrix(New, _matrix2))
            {
                throw new ArgumentException("++    ERROR    ++");
            }
            else
            {
                for (int i = 0; i < New.dateMatrix.GetLength(0); i++)
                {
                     New.dateMatrix[i] -= _matrix2.dateMatrix[i];
                }
                return New;
            }
        }
        public static Matrix operator *(Matrix _matrix1, Matrix _matrix2)//Переопределение оператора * Матриц*
        {
            Matrix New = new Matrix(_matrix1);
            if (!Check_Mul_Matrix(_matrix1, _matrix2))
            {
                throw new ArgumentException("++    ERROR    ++");
            }
            else
            {
                double[] newDate = new double[New.dateMatrix.GetLength(0)];
                for (int i = 0; i < New.dateMatrix.GetLength(0); i++)
                {
                    newDate[i] = 0;
                    for (int k = 0; k < New.dateMatrix.GetLength(1); k++)
                    {
                        newDate[i] += (New.dateMatrix[i] * _matrix2.dateMatrix[k]);
                    }
                }
                New.dateMatrix = null;
                New.dateMatrix = newDate;
                newDate = null;
                return New;
            }
        }
        public static Matrix operator *(Matrix _matrix, double _scalar)//Переопределение оператора * Матрица на скаляр*
        {
            Matrix New = new Matrix(_matrix);
            for (int i = 0; i < _matrix.dateMatrix.GetLength(0); i++)
            {
                _matrix.dateMatrix[i] *= _scalar;
            }
            return New;
        }
        public double this[int index1]//Вывод по элементно Матрици используя индексатор
        {
            get
            {
                if (index1 >= 0)
                {
                    return dateMatrix[index1];
                }
                else
                {
                    throw new ArgumentOutOfRangeException();
                }
            }
            set
            {
                if (index1 >= 0)
                {
                    dateMatrix[index1] = value;
                }
                else
                {
                    throw new ArgumentOutOfRangeException();
                }
            }
        }
        public override string ToString()//Переопределение вывода Матрицы через строки
        {
            String s = "";
            for (int i = 0; i < dateMatrix.GetLength(0); i++)
            {
                s += String.Format(" {0,4}", dateMatrix[i]);
            }
            return s;
        }
        
        public object Clone()
        {
            return dateMatrix.Clone();
        }
        public string ToString(string format, IFormatProvider formatProvider)
        {
            return dateMatrix.ToString();
        }
        IEnumerator<int> IEnumerable<int>.GetEnumerator()
        {
            return (IEnumerator<int>)GetEnumerator();
        }
        public Matrix GetEnumerator()
        {
            return new Matrix();
        }
    }
    class Vector : Matrix
    {
        private double[] dateVector;//Данные вектора
        private int VectorID;//ID вектора
        static int countVector = 1;//Колличество векторов

        public Vector()//Конструктор вектора по умолчанию
        {
            VectorID = countVector++;
            Console.WriteLine("++Конструктор 1 ID {0}++", VectorID);
            dateVector = null;
            Console.WriteLine("++             ++");
        }
        public Vector(double[] _dateVector)//Конструктор вектора по массиву
        {
            VectorID = countVector++;
            Console.WriteLine("++Конструктор 2 ID {0}++", VectorID);
            dateVector = new double[_dateVector.GetLength(0)];

            for (int i = 0; i < _dateVector.GetLength(0); i++)
            {
                dateVector[i] = _dateVector[i];
                Console.Write("   {0}", dateVector[i]);
            }
            Console.WriteLine("");
            Console.WriteLine("++             ++");
        }
        public Vector(Vector _vector)// Конструктор копирование Вектора
        {
            VectorID = countVector++;
            Console.WriteLine("++Конструктор 5 ID {0}++", VectorID);
            dateVector = new double[_vector.dateVector.GetLength(0)];

            for (int i = 0; i < _vector.dateMatrix.GetLength(0); i++)
            {
                dateVector[i] = _vector.dateVector[i];
                Console.Write("   {0}", dateVector[i]);
            }
            Console.WriteLine("++             ++");
        }
        public static bool Check_PlusMul_Vectors(Vector _vector1, Vector _vector2)//Метод проверки возможности сложения, отрицание или произведения двух матриц
        {
            return _vector1.dateVector.GetLength(0) == _vector2.dateVector.GetLength(0);
        }
        public static bool Check_Plus_Vector_Matrix(Vector _vector, Matrix _matrix)//Метод проверки возможности сложения Вектора и Матрицы
        {
            return _vector.dateVector.GetLength(0) == _matrix.dateMatrix.GetLength(0);
        }
        public static bool Check_Mul_Vector_Matrix(Vector _vector, Matrix _matrix)//Метод проверки возможности умножения Вектора и Матрицы
        {
            return _vector.dateVector.GetLength(0) == _matrix.dateMatrix.GetLength(1);
        }
        public double Max_Vector()//Метод поиска максимального элемента Вектора
        {
            double max = 0;
            for (int i = 0; i < dateVector.GetLength(0); i++)
            {
                if (max < dateVector[i])
                {
                    max = dateVector[i];
                }
            }
            return max;
        }
        public double Min_Vector()//Метод поиска минимального элемента Вектора
        {
            double min = Max_Vector();
            for (int i = 0; i < dateVector.GetLength(0); i++)
            {
                if (min > dateVector[i])
                {
                    min = dateVector[i];
                }
            }
            return min;
        }
        public static Vector operator +(Vector _vector1, Vector _vector2)//Переопределение оператора + Векторов
        {
            Vector New = new Vector(_vector1);
            if (!Check_PlusMul_Vectors(_vector1, _vector2))
            {
                throw new ArgumentException("++    ERROR    ++");
            }
            else
            {
                for (int i = 0; i < New.dateVector.GetLength(0); i++)
                {
                    New.dateVector[i] += _vector2.dateVector[i];
                }
                return New;
            }
        }
        public static Vector operator +(Vector _vector, Matrix _matrix)//Переопределение оператора + Вектора и Матрицы
        {
            Vector New = new Vector(_vector);
            if (!Check_Plus_Vector_Matrix(_vector, _matrix))
            {
                throw new ArgumentException("++    ERROR    ++");
            }
            else
            {
                for (int i = 0; i < New.dateVector.GetLength(0); i++)
                {
                    New.dateVector[i] += _matrix.dateMatrix[i];
                }
                return New;
            }
        }
        public static Vector operator -(Vector _vector1, Vector _vector2)//Переопределение оператора - Векторов
        {
            Vector New = new Vector(_vector1);
            if (!Check_PlusMul_Vectors(New, _vector2))
            {
                throw new ArgumentException("++    ERROR    ++");
            }
            else
            {
                for (int i = 0; i < New.dateVector.GetLength(0); i++)
                {
                    New.dateVector[i] -= _vector2.dateVector[i];
                }
                return New;
            }
        }
        public static Vector operator -(Vector _vector, Matrix _matrix)//Переопределение оператора - Вектороа и Матрицы
        {
            Vector New = new Vector(_vector);
            if (!Check_Plus_Vector_Matrix(New, _matrix))
            {
                throw new ArgumentException("++    ERROR    ++");
            }
            else
            {
                for (int i = 0; i < New.dateVector.GetLength(0); i++)
                {
                    New.dateVector[i] -= _matrix.dateMatrix[i];
                }
                return New;
            }
        }
        public static Vector operator *(Vector _vector1, Vector _vector2)//Переопределение оператора * Векторов
        {
            Vector New = new Vector(_vector1);
            if (!Check_PlusMul_Vectors(New, _vector2))
            {
                throw new ArgumentException("++    ERROR    ++");
            }
            else
            {
                for (int i = 0; i < New.dateVector.GetLength(0); i++)
                {
                    New.dateVector[i] *= _vector2.dateVector[i];
                }
                return New;
            }
        }
        public static Vector operator *(Vector _vector, Matrix _matrix)//Переопределение оператора * Вектора на Матрицы
        {
            Vector New = new Vector(_vector);
            if (!Check_Mul_Vector_Matrix(_vector, _matrix))
            {
                throw new ArgumentException("++    ERROR    ++");
            }
            else
            {
                for (int i = 0; i < New.dateVector.GetLength(0); i++)
                {
                    New.dateVector[i] *= _matrix.dateMatrix[i];
                }
                return New;
            }
        }
        public static Vector operator *(Vector _vector, double _scalar)//Переопределение оператора * Вектора на скаляр
        {
            Vector New = new Vector(_vector);
            for (int i = 0; i < _vector.dateVector.GetLength(0); i++)
            {
                    _vector.dateVector[i] *= _scalar;
            }
            return New;
        }
        public double this[int index1]//Вывод по элементно Вектора используя индексатор
        {
            get
            {
                if (index1 >= 0)
                {
                    return dateVector[index1];
                }
                else
                {
                    throw new ArgumentOutOfRangeException();
                }
            }
            set
            {
                if (index1 >= 0)
                {
                    dateVector[index1] = value;
                }
                else
                {
                    throw new ArgumentOutOfRangeException();
                }
            }
        }
        public override string ToString()//Переопределение вывода Вектора через строки
        {
            String s = "";
            for (int i = 0; i < dateVector.GetLength(0); i++)
            {
                s += String.Format(" {0,4}", dateVector[i]);
            }
            return s;
        }
    }
}
