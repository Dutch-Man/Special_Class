#pragma once
#include <iostream>
using namespace std;
class Student
{
private:
	char *Name;
	int Age;
	float Score;
public:
	Student()
	{
		Name = "Bluce";
		Age = 18;
		Score = 90.5;
	}
	void setName(char *name)
	{
		Name = name;
	}
	void setAge(int age)
	{
		Age = age;
	}
	void setScore(float score)
	{
		Score = score;
	}
	void showInfo()
	{
		cout << "Name = " << Name << endl
			 << "Age = " << Age << endl
			 << "Score = " << Score << endl;
	}
};

#include "singleton_tmpl.h"
#define Student_Singleton (Singleton<Student>::GetInstance())