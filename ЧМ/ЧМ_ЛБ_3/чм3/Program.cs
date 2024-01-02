using System;
using System.Data;
using System.IO;
using чм_3;

namespace чм_3
{
    class Program
    {
        static void Main(string[] args)
        {
            FileStream FileIn = new FileStream("IN.txt", FileMode.Open);
            StreamReader reader = new StreamReader(FileIn);

            int m = Convert.ToInt16(reader.ReadLine());
            uint n = Convert.ToUInt32(reader.ReadLine());
            double[] matData = new double[n* n];

            //Записываем матрицу
            for (uint i = 0; i < n; i++)
            {
                int ind = 0;
                string nums = reader.ReadLine();
                foreach (var num in nums.Split())
                {
                    matData[i * n + (ind++)] = Convert.ToDouble(num);
                }
            }
            reader.Close();

            Matrix Mat = new Matrix(n, n, matData);
            FileStream FileOut = new FileStream("OUT.txt", FileMode.Open);
            StreamWriter writer = new StreamWriter(FileOut);
            double[,] eigen = Mat.EigenVal(in writer);
            for (int i = 0; i < n; i += (int)eigen[i, 1])
            {
                writer.WriteLine("--------------------------------------------------------------");
                writer.WriteLine("Собственное число {0}: {1}", i, eigen[i, 0]);

                writer.WriteLine("Проверка собственного числа {0}: {1}", i, Mat.CheckEigen(eigen[i, 0]));
                if (m == 2)
                {
                    Matrix vect = Mat.EigenVector(eigen[i, 0]);
                    writer.WriteLine("Собственный вектор {0}: \n{1}", i, vect);
                    writer.WriteLine("Проверка собственного вектора {0}: \n{1}", i, Mat.CheckEigenVector(vect, eigen[i, 0]));
                }
                writer.WriteLine("Кратность собственного числа {0}: {1} ", i, eigen[i, 1]);
            }
            Console.WriteLine("Готово!");
            writer.Close();
        }
    }
}