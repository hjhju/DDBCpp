#include <iostream>

using namespace std;

/* Section11_08 ��ӹ��� �Լ��� ���߱� */

class Base
{
protected:
	int m_value;

public:
	Base(int value) : m_value(value)
	{

	}

	void print()
	{
		cout << "i'm base" << endl;
	}

};

class Derived : public Base
{
private:
	double m_d;
	using Base::print;  // �θ𿡼��� ���ٰ��������� �ڽĿ����� ���ٺҰ����ϰ� �ϱ�

public:
	Derived(int value) : Base(value)
	{

	}
	using Base::m_value;
	
};


int main()
{
	Base base(5);
	base.print();

	Derived derived(7);
	derived.m_value = 1024;
	//derived.print();

	return 0;
}