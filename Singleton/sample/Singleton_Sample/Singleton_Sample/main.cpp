#include "singleton_tmpl.h"
#include "Test_Class.h"
int main()
{
	cout << "��ͨʵ��" << endl;;
	Student studentA;
	cout << &studentA << endl;
	studentA.showInfo();
	cout << endl<< "�޸ģ�" << endl;
	cout << &studentA << endl;
	studentA.setName("New_Bruce");
	studentA.setAge(20);
	studentA.setScore(95.5);
	studentA.showInfo();
	
	cout << endl<< "����ģʽ��" << endl;
	cout << Student_Singleton << endl;
	Student_Singleton->showInfo();
	cout <<endl<< "�޸ģ�" << endl;
	cout << Student_Singleton << endl;
	Student_Singleton->setName("Singlton_Bruce");
	Student_Singleton->setAge(21);
	Student_Singleton->setScore(96.5);
	Student_Singleton->showInfo();
	
	return 0;
}