#pragma once
#include <iostream>
using namespace std;


template<class T>
class MyArray
{
public:
	//���캯��
	MyArray(int capacity)
	{
		m_Capacity = capacity;
		m_Size = 0;
		pAddress = new T[this->m_Capacity];
	}

	//��������
	MyArray(const MyArray& arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];

		for (int i = 0; i < this->m_Size; i++)
		{
			//���TΪ���󣬶��һ�����ָ�룬������Ҫ���� = ����������Ϊ����ȺŲ��� ���� ���Ǹ�ֵ��
			// ��ͨ���Ϳ���ֱ��= ����ָ��������Ҫ���
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



	//����
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

	T& operator[](int index)//����[]�������ʵ�����±귽ʽ��������  ���磺arr[1]=100;
	{
		return this->pAddress[index];  //ע�ⷵ��ֵ������ҪΪ���ã�������һ����ַ����Ҫ��Ϊ��ֵ���ڣ���Ϊ������޸�����ֵ��
	}

	//β�巨
	void Push_back(const T& val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			cout << "����û�пռ���" << endl;
			return;
		}

		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}


	void Pop_back()//βɾ��  ÿ����һ�Σ��ʹ��������ɾ��һ������
	{
		//ɾ��֮ǰҪ�ж�һ�£������״̬������������Ѿ�û�������ˣ��Ǿ�û��ɾ��
		if (this->m_Size == 0)
		{
			cout << "��������û�����ݣ��޷�ɾ��" << endl;
			return;
		}

		this->m_Size--;//������Ĵ�С��һ����ǰ��һ��λ�����û����ʲ����Ϳ�����,��Ϊ�߼�ɾ��
	}

	int getCapacity()//��ȡ���������
	{
		return this->m_Capacity;
	}

	int getSize()//��ȡ����Ĵ�С
	{
		return this->m_Size;
	}


private:
	T* pAddress;  //ָ��һ���ѿռ䣬����ռ�洢����������
	int m_Capacity; //����
	int m_Size;   // ��С
};