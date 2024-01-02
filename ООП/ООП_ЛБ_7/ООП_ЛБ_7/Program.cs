using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ООП_ЛБ_7
{
    class Program
    {
        static void Main(string[] args)
        {
            double[] arr = new double[4]{ 3,5,2,7};
            Vector vec = new Vector(arr);
            Console.WriteLine("Вектор1= {0}", Convert.ToString(vec));
            Console.ReadKey();
        }
    }
}
