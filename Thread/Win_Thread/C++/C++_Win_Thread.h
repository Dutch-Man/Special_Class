#include <windows.h>
#include <process.h>
#include <iostream>
using namespace std;
class Cpp_Win_Thread
{
public:
	void start()
	{
		if (_beginthread(start_thread, 0, this)<0)
		{
			cout << "_beginthread faild!" << endl;
		}
		return;
	}
	static void start_thread(LPVOID lpParam)
	{
		Cpp_Win_Thread *ptr = (Cpp_Win_Thread *)lpParam;
		ptr->run();
	}
	virtual void run() = 0;
};
class My_thread :public Cpp_Win_Thread
{
public:
	int m_num;
	My_thread(int n)
	{
		m_num = n;
	}
	void run()
	{
		while (true)
		{
			cout << "Thread.num = " << m_num << endl;
			Sleep(200);
		}
	}

};