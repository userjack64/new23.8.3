#include <iostream>
using namespace std;


template<class NameType, class AgeType>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		mName = name;
		mAge = age;
	}

	void showPerson()
	{
		cout << "name:  " << mName << "  age:  " << mAge << endl;
	}

public:
	NameType mName;
	AgeType mAge;

};

void test01()
{
	// ָ��NameType Ϊstring���ͣ�AgeType Ϊ int����   ��������ֱ����<>��������У�������������
	Person<string, int>P1("�����", 999);
	P1.showPerson();
}








int main()
{
	test01();

	system("pause");
	return 0;
}