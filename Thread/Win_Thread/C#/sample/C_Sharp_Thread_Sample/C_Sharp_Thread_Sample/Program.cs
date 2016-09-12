using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C_Sharp_Thread_Sample
{
    class Program
    {
        static void Main(string[] args)
        {
            My_thread thread1, thread2;
            thread1 = new My_thread(1);
            thread1.start();
            thread2 = new My_thread(2);
            thread2.start();
        }
    }
}
