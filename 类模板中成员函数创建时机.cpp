#include <iostream>
using namespace std;

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};

class Person2     //1���ȵ�������
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};


template<class T>
class MyClass
{
public:
	T obj; 
	//��ģ���еĳ�Ա������������һ��ʼ�ʹ����ģ�������ģ�����ʱ������
	void func1() { obj.showPerson1(); }
	void func2() { obj.showPerson2(); }       // 2������������ĳ�Ա����

};

void test01()
{
	MyClass<Person1> m;
	m.func1();
	//m.func2();   //��������˵���������òŻ�ȥ������Ա����
}






int main()
{
	test01();

	system("pause");
	return 0;
}