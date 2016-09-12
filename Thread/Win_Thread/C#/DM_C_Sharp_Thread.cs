using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace C_Sharp_Console_Test
{
    abstract  public class DM_Win_C_Sharp_Thread
    {
        Thread m_thread;
        ParameterizedThreadStart new_thread;
        static void start_thread(object ParObject)
        {
            DM_Win_C_Sharp_Thread ptr = (DM_Win_C_Sharp_Thread)ParObject;
            ptr.run();
        }
        abstract public void run();
        public DM_Win_C_Sharp_Thread()
        {
            new_thread = new ParameterizedThreadStart(start_thread);
        }
        public void start()
        {
            m_thread = new Thread(new_thread);
            m_thread.Start(this);
        }
    }
}

namespace C_Sharp_Console_Test
{
    public class My_thread : DM_Win_C_Sharp_Thread
    {
        public int m_num;
        public My_thread(int n)
        {
            m_num = n;
        }
        public override void run()
        {
            while (true)
            {
                Console.WriteLine("Thread.num = {0}", m_num);
                Thread.Sleep(200);
            }

        }
    }
};