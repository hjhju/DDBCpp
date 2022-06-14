#include <iostream>

using namespace std;

/* Section11_06 유도된 클래스에 새로운 기능 추가하기 */

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
		Base::m_value = value; // 부모클래스에서 protected로 명시되어있으면 가능
	}

};

int main()
{


	return 0;
}