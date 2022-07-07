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

// �����Ϸ��� speciallizer �ϴ� ���� ��
// ���� cpp�� �ű��� �ʾƵ� ��
// ����� �������� �ɰ��� ����ص� ��
template <>
void Storage<double>::print()
{
	std::cout << "Double Type ";
	std::cout << std::scientific << m_value << std::endl;
}