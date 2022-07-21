#pragma once
#include <iostream>

// std::auto_ptr<int> �� ����, ����ϰ� ����, c++98�� ���԰�, c++11, 17������ �����

template <class T>
class AutoPtr
{
public:
	T* m_ptr;

public:
	AutoPtr(T* ptr = nullptr) : m_ptr(ptr)
	{
		std::cout << "AutoPtr default constructor" << std::endl;

	}

	~AutoPtr()
	{
		std::cout << "AutoPtr destructor" << std::endl;

		if (m_ptr != nullptr) delete m_ptr;
	}


	// L-value reference
	AutoPtr(const AutoPtr& a)
	{
		std::cout << "AutoPtr copy constructor" << std::endl;

		// Deep copy
		// Resource& operator = (Resource& res) �� �����
		m_ptr = new T;
		// ���������δ� ������ �����ε��� �Ͼ�°�
		*m_ptr = *a.m_ptr; 
	}

	AutoPtr& operator = (const AutoPtr& a)
	{
		std::cout << "AutoPtr copy assignment" << std::endl;

		// �Է��� �ڱ� �ڽ��ΰͿ� ��� (prevent self-assignment)
		if (&a == this)
			return *this;
		
		if (m_ptr != nullptr) delete m_ptr;

		// Deep copy
		m_ptr = new T;
		*m_ptr = *a.m_ptr; //��������

		return *this;
	}

	//AutoPtr(const AutoPtr& a) = delete;
	//AutoPtr& operator = (const AutoPtr& a) = delete;
	// 
	// R-value reference
	AutoPtr(AutoPtr&& a)
	{
		m_ptr = a.m_ptr; //��������
		a.m_ptr = nullptr; // ù��° �����͸� null�� �ٲ���� -> ������� ������

		std::cout << "AutoPtr move constructor" << std::endl;
	}

	AutoPtr& operator = (AutoPtr&& a)
	{
		std::cout << "AutoPtr move assignment" << std::endl;

		// �Է��� �ڱ� �ڽ��ΰͿ� ���
		if (&a == this)
			return *this;
		
		if(!m_ptr) delete m_ptr;

		// ���� ����
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr; // really necessary?

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};