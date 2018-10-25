using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Factorial
{
    class Factorial
    {
        public static int factorial(int n)
        {
            int result;
            if (n == 0)
                result = 1;
            else
                result = n * factorial(n - 1);
            return result;
        }
        



        static void Main(string[] args)
        {
            string n;
            Console.WriteLine("enter number: ");
            n = Console.ReadLine();
            int number = Convert.ToInt32(n);
            
            Console.WriteLine("result: " + factorial(number));
            Console.Read();
        }
    }
}
