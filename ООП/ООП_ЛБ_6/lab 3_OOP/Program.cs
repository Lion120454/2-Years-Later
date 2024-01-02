using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_3_OOP
{
    class Program
    {
        static void Main(string[] args)
        {
            int m = 5, n = 4;
            double[,] arr = new double[m, n];
            Random r = new Random();
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    arr[i, j] = r.Next(1, 15);
                }
            }
            Matrix mat1 = new Matrix(m,n,arr);
            double[,] arr1 = new double[m, m];
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    arr1[i, j] = r.Next(1, 15);
                }
            }
            Matrix mat2 = new Matrix(m,arr1);
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    arr[i, j] = r.Next(1, 15);
                }
            }
            Matrix mat3 = new Matrix(arr);
            Console.WriteLine("Макс. элемент матрицы mat2= ",mat2.Max_Matrix());
            Console.WriteLine("Мин. элемент матрицы mat2= ",mat2.Max_Matrix());
            Matrix mat4 = new Matrix(mat1);
            try
            {
                mat1 = mat1 + mat4;
                Console.WriteLine(Convert.ToString(mat4));
            }
            catch(ArgumentException e)
            {
                Console.WriteLine(e);
            }

            try
            {
                mat3 = mat3 - mat1;
                Console.WriteLine(Convert.ToString(mat3));
            }
            catch (ArgumentException e)
            {
                Console.WriteLine(e);
            }

            try
            {
                mat1 = mat3 * mat3;
                Console.WriteLine(Convert.ToString(mat1));
            }
            catch (ArgumentException e)
            {
                Console.WriteLine(e);
            }
            mat2 = mat2 * 3;
            Console.WriteLine("mat2[2,3]= {0}", mat2[2, 3]);
            Console.ReadKey();
        }
    }
}
