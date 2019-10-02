using System;

namespace SimpleArrayApp
{
    public class Program
    {
        public static void Main()
        {
            char[] v = new char[11] {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
            
            string w = "";
            for(int i = 0; i < v.Length; i++)
            {
                w += v[i];
            }

            Console.WriteLine(w);
            Console.Read();
        }
    }
}