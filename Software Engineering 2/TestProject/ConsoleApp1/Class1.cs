using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Class1
    {
        internal void doIt()
        {
            string s1 = "hello";
            var stopwatch = new Stopwatch();
            stopwatch.Start();
            for(int i = 0; i<100000; i++)
            {
                s1 += "AI";
            }
            stopwatch.Stop();
            stopwatch.Reset();

            Console.WriteLine(stopwatch.ElapsedMilliseconds);

            var sb = new StringBuilder();

            sb.Append("hello");

            stopwatch.Start();
            for (int i = 0; i < 100000; i++)
            {
                sb.Append("AI");
            }

            string a = sb.ToString();

            stopwatch.Stop();

            Console.WriteLine(stopwatch.ElapsedMilliseconds);

        }
    }

    


}
