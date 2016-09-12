#include "singleton_tmpl.h"
#include "Test_Class.h"
int main()
{
	cout << "普通实例" << endl;;
	Student studentA;
	cout << &studentA << endl;
	studentA.showInfo();
	cout << endl<< "修改：" << endl;
	cout << &studentA << endl;
	studentA.setName("New_Bruce");
	studentA.setAge(20);
	studentA.setScore(95.5);
	studentA.showInfo();
	
	cout << endl<< "单例模式：" << endl;
	cout << Student_Singleton << endl;
	Student_Singleton->showInfo();
	cout <<endl<< "修改：" << endl;
	cout << Student_Singleton << endl;
	Student_Singleton->setName("Singlton_Bruce");
	Student_Singleton->setAge(21);
	Student_Singleton->setScore(96.5);
	Student_Singleton->showInfo();
	
	return 0;
}