#include <iostream>

using namespace std;

/* Section11_06 ������ Ŭ������ ���ο� ��� �߰��ϱ� */

class Base
{
protected:
	int m_value;

public:
	Base(int value) : m_value(value)
	{

	}
};

class Derived : public Base
{
private:

public:
	Derived(int value) : Base(value)
	{

	}

	void setValue(int value)
	{
		Base::m_value = value; // �θ�Ŭ�������� protected�� ��õǾ������� ����
	}

};

int main()
{


	return 0;
}