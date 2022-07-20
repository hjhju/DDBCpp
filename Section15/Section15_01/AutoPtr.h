#pragma once
#include <iostream>

// std::auto_ptr<int> 가 존재, 비슷하게 구현, c++98에 들어왔고, c++11, 17에서는 사라짐

template <class T>
class AutoPtr
{
public:
	T* m_ptr = nullptr;
public:
	AutoPtr(T* ptr = nullptr) : m_ptr(ptr)
	{

	}

	~AutoPtr()
	{
		if (m_ptr != nullptr) delete m_ptr;
	}

	AutoPtr(AutoPtr& a)
	{
		m_ptr = a.m_ptr; //복사해줌
		a.m_ptr = nullptr; // 첫번째 포인터를 null로 바꿔버림 -> 지울수도 없어짐
	}

	AutoPtr& operator = (AutoPtr& a)
	{
		// 입력이 자기 자신인것에 대비
		if (&a == this)
			return *this;
		delete m_ptr;

		// 소유권 이전!
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};