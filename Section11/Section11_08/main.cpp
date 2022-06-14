#include <iostream>

using namespace std;

/* Section11_08 상속받은 함수를 감추기 */

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
	using Base::print;  // 부모에서는 접근가능하지만 자식에서는 접근불가능하게 하기

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