using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {

            var s = Singleton.Instance;


            var test = new Class1();

            test.doIt();

        }
    }
}
