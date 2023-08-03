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
	// 指定NameType 为string类型，AgeType 为 int类型   创建对象直接在<>后面跟就行！！！！！！！
	Person<string, int>P1("孙悟空", 999);
	P1.showPerson();
}








int main()
{
	test01();

	system("pause");
	return 0;
}