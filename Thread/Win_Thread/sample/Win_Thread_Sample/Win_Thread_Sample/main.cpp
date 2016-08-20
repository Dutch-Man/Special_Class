#include <iostream>
#include "Win_Thread.h"
using namespace std;

class Thread_Test :public Win_Thread
{
public:
	void run()
	{
		cout << "run ..." << endl;
	}

};

int main()
{

	Thread_Test thread;
	thread.start();
	Sleep(1000);
	return 0;
}