#pragma once
#include <iostream>
using namespace std;


template<class T>
class MyArray
{
public:
	//构造函数
	MyArray(int capacity)
	{
		m_Capacity = capacity;
		m_Size = 0;
		pAddress = new T[this->m_Capacity];
	}

	//拷贝构造
	MyArray(const MyArray& arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];

		for (int i = 0; i < this->m_Size; i++)
		{
			//如果T为对象，而且还包含指针，必须需要重载 = 操作符，因为这个等号不是 构造 而是赋值，
			// 普通类型可以直接= 但是指针类型需要深拷贝
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	MyArray& operator=(const MyArray& myarray)
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		
		this->m_Capacity = myarray.m_Capacity;
		this->m_Size = myarray.m_Size;
		this->pAddress = new T[this->m_Capacity];

		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = myarray[i];
		}

		return *this;
	}



	//析构
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
	}

	T& operator[](int index)//重载[]运算符，实现用下标方式访问数组  例如：arr[1]=100;
	{
		return this->pAddress[index];  //注意返回值的类型要为引用，即返回一个地址，它要作为左值存在，因为你可以修改他的值嘛
	}

	//尾插法
	void Push_back(const T& val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			cout << "数组没有空间了" << endl;
			return;
		}

		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}


	void Pop_back()//尾删法  每调用一次，就从数组最后删除一个数据
	{
		//删除之前要判断一下，数组的状态，如果数组中已经没有数据了，那就没法删了
		if (this->m_Size == 0)
		{
			cout << "数组中已没有数据，无法删除" << endl;
			return;
		}

		this->m_Size--;//把数组的大小减一，往前移一个位置让用户访问不到就可以了,即为逻辑删除
	}

	int getCapacity()//获取数组的容量
	{
		return this->m_Capacity;
	}

	int getSize()//获取数组的大小
	{
		return this->m_Size;
	}


private:
	T* pAddress;  //指向一个堆空间，这个空间存储真正的数据
	int m_Capacity; //容量
	int m_Size;   // 大小
};