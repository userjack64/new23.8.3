#include <iostream>
using namespace std;

template<class NameType, class AgeType = int>    //��ģ�����  ����Ĭ�ϲ���  
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

//1����ģ��û���Զ������Ƶ���ʹ�÷�ʽ
void test01()
{
	// Person p("�����", 1000); // ���� ��ģ��ʹ��ʱ�򣬲��������Զ������Ƶ�

	Person <string, int>p("�����", 1000); //����ʹ����ʾָ�����͵ķ�ʽ��ʹ����ģ��
	p.showPerson();
}

void test02()
{
	Person <string> p("��˽�", 999); //��ģ���е�ģ������б� ����ָ��Ĭ�ϲ���
	p.showPerson();
}








int main()
{
	test01();

	test02();


	system("pause");
	return 0;
}