#include <iostream>
using namespace std;

template<class NameType, class AgeType = int>    //类模板可以  给出默认参数  
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
		cout << "name: " << mName << " age: " << mAge << endl;
	}

public:
	NameType mName;
	AgeType mAge;
};

//1、类模板没有自动类型推导的使用方式
void test01()
{
	// Person p("孙悟空", 1000); // 错误 类模板使用时候，不可以用自动类型推导

	Person <string, int>p("孙悟空", 1000); //必须使用显示指定类型的方式，使用类模板
	p.showPerson();
}

void test02()
{
	Person <string> p("猪八戒", 999); //类模板中的模板参数列表 可以指定默认参数
	p.showPerson();
}








int main()
{
	test01();

	test02();


	system("pause");
	return 0;
}