using System;

namespace lab_3_OOP
{
    public class Matrix//:ICloneable, IFormattable,IEnumerator<double>;
    {
        public int lines//Get_Строки
        {
            get
            {
                return Lines;
            }
            private set
            {
                Lines = value;
            }
        }
        public int columns//Get_Столбцы
        {
            get
            {
                return Columns;
            }
            private set
            {
                Columns = value;
            }
        }
        private int Lines;//Строки
        private int Columns;//Столбцы
        private double[,] date;//Информация
        private int id;//id
        static int countMatrix = 1;//Колличество матриц

        public Matrix()//Конструктор по умолчанию
        {
            id = countMatrix++;
            Console.WriteLine("++Конструктор 1 ID {0}++", id);
            lines = 0;
            columns = 0;
            date = null;
            Console.WriteLine("++             ++");
        }
        public Matrix(int _lines, int _columns, double[,] _date)//Конструктор для прямоугольной матрицы по размерам
        {
            id = countMatrix++;
            Console.WriteLine("++Конструктор 2 ID {0}++", id);
            lines = _lines;
            columns = _columns;
            date = new double[lines, columns];

            for (int i = 0; i < lines; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    date[i, j] = _date[i, j];
                    Console.Write("   {0}", date[i, j]);
                }
                Console.WriteLine();
            }
            Console.WriteLine("++             ++");
        }
        public Matrix(int _lines, double[,] _date): this(_lines,_lines,_date)//Конструктор для квадратной матрицы
        {
        }
        public Matrix(double[,] _date) : this(_date.GetLength(0), _date.GetLength(1), _date)//Конструктор для прямоугольной матрицы по двумерному массиву
        {
        }
        public Matrix(Matrix _matrix)//Копирование
        {
            id = countMatrix++;
            Console.WriteLine("++Конструктор 5 ID {0}++", id);
            lines = _matrix.lines;
            columns = _matrix.columns;

            date = new double[lines, columns];
            for (int i = 0; i < lines; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    date[i, j] = _matrix.date[i, j];
                    Console.Write("   {0}", date[i, j]);
                }
                Console.WriteLine();
            }
            Console.WriteLine("++             ++");
        }
        public static bool Check_Plus(Matrix _matrix1, Matrix _matrix2)//Метод проверки возможности сложения двух матриц
        {
            return (_matrix1.columns == _matrix2.columns) && (_matrix1.lines == _matrix2.lines);
        }
        public static bool Check_Mul(Matrix _matrix1, Matrix _matrix2)//Метод проверки возможности умножения двух матриц
        {
            return (_matrix1.columns == _matrix2.lines);
        }
        public double Max_Matrix()//Метод поиска максимального элемента
        {
            double max = 0;
            for (int i = 0; i < lines; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if (max < date[i, j])
                    {
                        max = date[i, j];
                    }
                }
            }
            return max;
        }
        public double Min_Matrix()//Метод поиска минимального элемента
        {
            double min = Max_Matrix();
            for (int i = 0; i < lines; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if (min > date[i, j])
                    {
                        min = date[i, j];
                    }
                }
            }
            return min;
        }
        public static Matrix operator +(Matrix _matrix1, Matrix _matrix2)//Переопределение оператора +
        {
            Matrix New = new Matrix(_matrix1);
            if (!Check_Plus(New, _matrix2))
            {
                throw new ArgumentException("++    ERROR    ++");
            }
            else
            {
                for (int i = 0; i < New.lines; i++)
                {
                    for (int j = 0; j < New.columns; j++)
                    {
                        New.date[i, j] += _matrix2.date[i, j];
                    }
                }
                return New;
            }
        }
        public static Matrix operator -(Matrix _matrix1, Matrix _matrix2)//Переопределение оператора -
        {
            Matrix New = new Matrix(_matrix1);
            if (!Check_Plus(New, _matrix2))
            {
                throw new ArgumentException("++    ERROR    ++");
            }
            else
            {
                for (int i = 0; i < New.lines; i++)
                {
                    for (int j = 0; j < New.columns; j++)
                    {
                        New.date[i, j] -= _matrix2.date[i, j];
                    }
                }
                return New;
            }
        }
        public static Matrix operator *(Matrix _matrix1, Matrix _matrix2)//Переопределение оператора *
        {
            Matrix New = new Matrix(_matrix1);
            if (!Check_Mul(_matrix1, _matrix2))
            {
                throw new ArgumentException("++    ERROR    ++");
            }
            else
            {
                double[,] newDate = new double[New.lines, New.columns];
                for (int i = 0; i < New.lines; i++)
                {
                    for (int j = 0; j < _matrix2.columns; j++)
                    {
                        newDate[i, j] = 0;
                        for (int k = 0; k < New.columns; k++)
                        {
                            newDate[i, j] += (New.date[i, k] * _matrix2.date[k, j]);
                        }
                    }
                }
                New.date = null;
                New.date = newDate;
                newDate = null;
                return New;
            }
        }
        public static Matrix operator *(Matrix _matrix, double _scalar)//Переопределение оператора * на скаляр
        {
            Matrix New = new Matrix(_matrix);
            for (int i = 0; i < _matrix.lines; i++)
            {
                for (int j = 0; j < _matrix.columns; j++)
                {
                    _matrix.date[i, j] *= _scalar;
                }
            }
            return New;
        }
        public double this[int index1, int index2]//Вывод по элементно используя индексатор
        {
            get
            {
                if (index1 >= 0 && index2 >= 0)
                {
                    return date[index1, index2];
                }
                else
                {
                    throw new ArgumentOutOfRangeException();
                }
            }
            set
            {
                if (index1 >= 0 && index2 >= 0)
                {
                    date[index1, index2] = value;
                }
                else
                {
                    throw new ArgumentOutOfRangeException();
                }
            }
        }
        public override string ToString()//Переопределение вывода матрицы через строки
        {

            String s = "";
            for (int i = 0; i < lines; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    s += String.Format(" {0,4}", date[i, j]);
                }
                s += String.Format("\n");
            }
            return s;
        }
        public object Clone()
        {
            return new Matrix(lines, columns,date);
        }
        public string ToString(Matrix mat)
        {
            return this.ToString(mat);
        }
        
    }
}


//интерфейс клонирования, перечесления,форматирования
