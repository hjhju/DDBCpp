#pragma once
#include <iostream>

template <class T>
class Storage
{
private:
	T m_value;
public:
	Storage(T value)
	{
		m_value = value;
	}
	~Storage()
	{

	}
	void print()
	{
		std::cout << m_value << std::endl;
	}
};

// 컴파일러가 speciallizer 하는 것을 모름
// 굳이 cpp로 옮기지 않아도 됨
// 헤더를 여러개로 쪼개서 사용해도 됨
template <>
void Storage<double>::print()
{
	std::cout << "Double Type ";
	std::cout << std::scientific << m_value << std::endl;
}