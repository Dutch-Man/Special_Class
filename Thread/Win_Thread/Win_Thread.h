#include <windows.h>
#include <process.h>
#include <iostream>
using namespace std;
class Win_Thread
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
		Win_Thread *ptr = (Win_Thread *)lpParam;
		ptr->run();
	}
	virtual void run() = 0;
};