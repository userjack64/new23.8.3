#include <iostream>
using namespace std;


template<class NameType, class AgeType = int>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->mName = name;
		this->mAge = age;
	}
	void showPerson()
	{
		cout << "name: " << this->mName << " age: " << this->mAge << endl;
	}
public:
	NameType mName;
	AgeType mAge;
};

//1、指定传入的类型(向函数  printPerson1  传参的方式)，还是要在类外创建一个函数！！！！！！
void printPerson1(Person<string, int>& p) //直接显示对象的数据类型 string 和 int 
{
	p.showPerson();
}

void test01()
{
	Person <string, int >p("孙悟空", 100);
	printPerson1(p); //记得传入对象p
}


//2、参数模板化，顾名思义，先创建一个模板
template <class T1, class T2>
void printPerson2(Person<T1, T2>& p)
{
	p.showPerson();
	cout << "T1的类型为： " << typeid(T1).name() << endl;   //显示类型名称，想看的话可以加这两句代码
	cout << "T2的类型为： " << typeid(T2).name() << endl;
}

void test02()
{
	Person <string, int >p("猪八戒", 90);
	printPerson2(p);
}


//3、整个类模板化
template<class T>
void printPerson3(T& p)
{
	p.showPerson();
	cout << "T的类型为： " << typeid(T).name() << endl;
}


void test03()
{
	Person <string, int >p("唐僧", 30);
	printPerson3(p);
}

int main()
{
	test01();
	test02();
	test03();

	system("pause");
	return 0;
}