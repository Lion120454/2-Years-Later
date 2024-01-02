using System;
using PolStrLib;
using System.IO;

namespace lab_1
{
    class Program
    {
        static int Sxod(double x,double a, double b)
        {
            if (a < x && x < b)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        static int Degree(double e)
        {
            int count=0;
            while (e != 1)
            {
                e = e * 10;
                count++;
            }
            return count;
        }
        static void Main(string[] args)
        {
            FileStream FileIn = new FileStream("IN.txt",FileMode.Open);
            StreamReader reader = new StreamReader(FileIn);

            int n = Convert.ToInt32(reader.ReadLine());
            string pstr, expr = reader.ReadLine();
            PolStr.StrToPolStr(expr, out pstr, 4);
            double a = Convert.ToDouble(reader.ReadLine());
            double b = Convert.ToDouble(reader.ReadLine());
            double e = Convert.ToDouble(reader.ReadLine());
            FileIn.Close();
            reader.Close();
            if (n == 1)//1:Метод Дихотомии
            {
                Console.WriteLine("Метод Дихотомии:");
                if (PolStr.Error == Error.OK)
                {
                    double c = 0.5 * (a + b),ex=1;
                    while (Math.Abs((b - a)/2) >= e|| Math.Abs((PolStr.EvalPolStr(pstr, b, 0) - PolStr.EvalPolStr(pstr, a, 0)) / 2)>=e)
                    {
                        if (PolStr.EvalPolStr(pstr, a, 0) * PolStr.EvalPolStr(pstr, c, 0) < 0)
                        {
                            b = c;
                        }
                        else
                        {
                            a = c;
                        }
                        c = 0.5 * (a + b);
                        ex = Math.Abs((b - a) / 2);
                    }

                    c = Math.Round(c, Degree(e));
                    FileStream FileOut = new FileStream("OUT.txt", FileMode.Create);
                    StreamWriter writer = new StreamWriter(FileOut);
                    writer.WriteLine("Метод Дихотомии");
                    writer.WriteLine("x= {0}", c);
                    writer.WriteLine("f(x)= {0}", PolStr.EvalPolStr(pstr, c, 0).ToString("e4"));
                    writer.WriteLine("e= +-{0}", ex.ToString("e4"));
                    writer.Close();
                    FileOut.Close();
                    Console.WriteLine("{0}", c);
                }
                else
                {
                    Console.WriteLine(PolStr.Error);
                }
            }
            if (n == 2)//2:Метод Ньютона
            {
                Console.WriteLine("Метод Ньютона:");
                if (PolStr.Error == Error.OK)
                {
                    double x0=0, xk, xkp1,e1=1;
                    if(PolStr.EvalPolStr(pstr, a, 0)* PolStr.EvalPolStr(pstr, a, 2) > 0)
                    {
                        x0 = a;
                    }
                    if (PolStr.EvalPolStr(pstr, b, 0) * PolStr.EvalPolStr(pstr, b, 2) > 0)
                    {
                        x0 = b;
                    }
                    xk = x0 - (PolStr.EvalPolStr(pstr, x0, 0)) / (2 * x0);
                    xkp1 = xk - (PolStr.EvalPolStr(pstr, xk, 0)) / (2 * xk);

                    while (Math.Abs(xk - xkp1) >= e || Math.Abs(PolStr.EvalPolStr(pstr, xk, 0) - PolStr.EvalPolStr(pstr, xkp1, 0)) >=e)
                    {
                        xk = xkp1;
                        xkp1 = xk - (PolStr.EvalPolStr(pstr, xk, 0)) / (2 * xk);
                    }

                    xkp1 = Math.Round(xkp1, Degree(e));
                    e1 = Math.Abs(xkp1 - x0);
                    FileStream FileOut = new FileStream("OUT.txt", FileMode.Create);
                    StreamWriter writer = new StreamWriter(FileOut);
                    writer.WriteLine("Метод Ньютона");
                    writer.WriteLine("x= {0}", xkp1);
                    writer.WriteLine("f(x)= {0}", PolStr.EvalPolStr(pstr, xkp1, 0).ToString("e4"));
                    writer.WriteLine("e= +-{0}", e1.ToString("e4"));
                    writer.Close();
                    FileOut.Close();
                    Console.WriteLine("{0}", xkp1);
                }
                else
                {
                    Console.WriteLine(PolStr.Error);
                }
            }
            if (n == 3)//3:Метод Хорд
            {
                Console.WriteLine("Метод Хорд");
                if (PolStr.Error == Error.OK)
                {
                    double xkm1 = a, xk = b, xkp1 = 0, e1 = 0,tmp;
                    do
                    {
                        tmp = xkp1;
                        xkp1 = xk - PolStr.EvalPolStr(pstr, xk, 0) * (xkm1 - xk) /
                            (PolStr.EvalPolStr(pstr, xkm1, 0) - PolStr.EvalPolStr(pstr, xk, 0));
                            
                        xkm1 = xk;
                        xk = tmp;
                    }while (Math.Abs(xkp1 - xk) > e|| Math.Abs(PolStr.EvalPolStr(pstr, xkp1, 0) - PolStr.EvalPolStr(pstr, xk, 0))>=e);

                    xk = Math.Round(xk, Degree(e));
                    e1 = Math.Abs(xk - xkm1);
                    FileStream FileOut = new FileStream("OUT.txt", FileMode.Create);
                    StreamWriter writer = new StreamWriter(FileOut);
                    writer.WriteLine("Метод Хорд");
                    writer.WriteLine("x= {0}", xk);
                    writer.WriteLine("f(x)= {0}", PolStr.EvalPolStr(pstr, xk, 0).ToString("e4"));
                    writer.WriteLine("e= +-{0}", e1.ToString("e4"));
                    writer.Close();
                    FileOut.Close();
                    Console.WriteLine("{0}", xk);
                }
                else
                {
                    Console.WriteLine(PolStr.Error);
                }
            }
            if (n == 4)//Метод Комбинированный
            {
                Console.WriteLine("Метод Комбинированный");
                if (PolStr.Error == Error.OK)
                {
                    double e1 = 0;
                    do
                    {
                        if (PolStr.EvalPolStr(pstr, a, 0) * PolStr.EvalPolStr(pstr, a, 2) < 0)
                        {
                            a += (b - a) / (PolStr.EvalPolStr(pstr, a, 0) - PolStr.EvalPolStr(pstr, b, 0)) * PolStr.EvalPolStr(pstr, a, 0);
                        }
                        else
                        {
                            a -= PolStr.EvalPolStr(pstr, a, 0) / PolStr.EvalPolStr(pstr, a, 1);
                        }
                        if (PolStr.EvalPolStr(pstr, b, 0) * PolStr.EvalPolStr(pstr, b, 2) < 0)
                        {
                            b += (a - b) / (PolStr.EvalPolStr(pstr, b, 0) - PolStr.EvalPolStr(pstr, a, 0)) * PolStr.EvalPolStr(pstr, b, 0);
                        }
                        else
                        {
                            b -= PolStr.EvalPolStr(pstr, b, 0) / PolStr.EvalPolStr(pstr, b, 1);
                        }
                        e1 = Math.Abs((b - a) / 2);
                    } while (Math.Abs(b - a) > 2 * e || Math.Abs(PolStr.EvalPolStr(pstr, b, 0) - PolStr.EvalPolStr(pstr, a, 0) / 2) >= e);

                    double x = Math.Round((a + b) / 2, Degree(e));
                    FileStream FileOut = new FileStream("OUT.txt", FileMode.Create);
                    StreamWriter writer = new StreamWriter(FileOut);
                    writer.WriteLine("Метод Комб");
                    writer.WriteLine("x= {0}", x);
                    writer.WriteLine("f(x)= {0}",PolStr.EvalPolStr(pstr, x, 0).ToString("e4"));
                    writer.WriteLine("e= +-{0}", e1.ToString("e4"));
                    writer.Close();
                    FileOut.Close();
                    Console.WriteLine("{0}", x);
                }
                else
                {
                    Console.WriteLine(PolStr.Error);
                }
            }
            if (n == 5)//Метод Золотого Сечения
            {
                Console.WriteLine("Метод Золотого Сечения");
                if (PolStr.Error == Error.OK)
                {
                    double x, e1;
                    double Y = (Math.Sqrt(5) + 1) / 2;
                    do
                    {
                        double d = a + (b - a) / Y;
                        double c = a + (b - a) / Math.Pow(Y, 2);

                        if ((PolStr.EvalPolStr(pstr, a, 0) * PolStr.EvalPolStr(pstr, d, 0)) > 0)
                        {
                            a = c;
                        }
                        else
                        {
                            b = d;
                        }
                        x = (a + b) / 2;
                        e1 = Math.Abs((b - a) / 2);
                    }
                    while (Math.Abs((b - a) / 2) >= e|| Math.Abs(PolStr.EvalPolStr(pstr, b, 0)- PolStr.EvalPolStr(pstr, a, 0)/2)>=e);

                    x = Math.Round((a + b) / 2, Degree(e));
                    FileStream FileOut = new FileStream("OUT.txt", FileMode.Create);
                    StreamWriter writer = new StreamWriter(FileOut);
                    writer.WriteLine("Метод Золотого Сечения");
                    writer.WriteLine("x= {0}", x);
                    writer.WriteLine("f(x)= {0}", PolStr.EvalPolStr(pstr, x, 0).ToString("e4"));
                    writer.WriteLine("e= +-{0}", e1.ToString("e4"));
                    writer.Close();
                    FileOut.Close();
                    Console.WriteLine("{0}", x);
                }
                else
                {
                    Console.WriteLine(PolStr.Error);
                }
            }
            if (n == 6)//Метод Итераций
            {
                Console.WriteLine("Метод Итераций");
                if (PolStr.Error != Error.OK)
                {
                    Console.WriteLine(PolStr.Error);
                    return;
                }
                double x = a + b / 2;
                double x0;
                do
                {
                    x0 = x;
                    x = x - (PolStr.EvalPolStr(pstr, x0, 0) / Math.Max(PolStr.EvalPolStr(pstr, a, 1), PolStr.EvalPolStr(pstr, b, 1)));
                }
                while ((Math.Abs(x - x0) >= e) || Math.Abs(PolStr.EvalPolStr(pstr, x, 0)- PolStr.EvalPolStr(pstr, x0, 0))>=e);

                x = Math.Round(x, Degree(e));
                FileStream FileOut = new FileStream("OUT.txt", FileMode.Create);
                StreamWriter writer = new StreamWriter(FileOut);
                writer.WriteLine("Метод Золотого Сечения");
                writer.WriteLine("x= {0}", x);
                writer.WriteLine("f(x)= {0}", PolStr.EvalPolStr(pstr, x, 0).ToString("e4"));
                writer.WriteLine("e= +-{0}", e.ToString("e4"));
                writer.Close();
                FileOut.Close();
                Console.WriteLine("{0}", x);
            }
            Console.ReadKey();
        }
    }
}
