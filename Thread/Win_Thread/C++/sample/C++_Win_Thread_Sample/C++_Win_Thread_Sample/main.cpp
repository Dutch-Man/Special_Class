#include "C++_Win_Thread.h"
int main()
{
	My_thread thread1(1), thread2(2);
	thread1.start();
	thread2.start();
	Sleep(10000);
	return 0;
}