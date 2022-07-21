#pragma once
#include <iostream>

// std::auto_ptr<int> 가 존재, 비슷하게 구현, c++98에 들어왔고, c++11, 17에서는 사라짐

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
		// Resource& operator = (Resource& res) 가 실행됨
		m_ptr = new T;
		// 내부적으로는 연산자 오버로딩이 일어나는것
		*m_ptr = *a.m_ptr; 
	}

	AutoPtr& operator = (const AutoPtr& a)
	{
		std::cout << "AutoPtr copy assignment" << std::endl;

		// 입력이 자기 자신인것에 대비 (prevent self-assignment)
		if (&a == this)
			return *this;
		
		if (m_ptr != nullptr) delete m_ptr;

		// Deep copy
		m_ptr = new T;
		*m_ptr = *a.m_ptr; //복사해줌

		return *this;
	}

	//AutoPtr(const AutoPtr& a) = delete;
	//AutoPtr& operator = (const AutoPtr& a) = delete;
	// 
	// R-value reference
	AutoPtr(AutoPtr&& a)
	{
		m_ptr = a.m_ptr; //복사해줌
		a.m_ptr = nullptr; // 첫번째 포인터를 null로 바꿔버림 -> 지울수도 없어짐

		std::cout << "AutoPtr move constructor" << std::endl;
	}

	AutoPtr& operator = (AutoPtr&& a)
	{
		std::cout << "AutoPtr move assignment" << std::endl;

		// 입력이 자기 자신인것에 대비
		if (&a == this)
			return *this;
		
		if(!m_ptr) delete m_ptr;

		// 얕은 복사
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr; // really necessary?

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};