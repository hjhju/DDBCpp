#include <iostream>

using namespace std;

/* Section11_05 상속과 접근 지정자 */

class Base
{
public:
	int m_public;
protected:
	int m_protected;
private:
	int m_private;
};

/*
class Derived : public Base
{
public:
	Derived()
	{
		m_protected = 123; // protected는 밖에서는 안되지만 자식 클래스에서는 접근가능
		//m_private = 123; // private는 안됨
	}
};
*/

class Derived : private Base
{
public:
	Derived()
	{
		Base::m_public; // this->m_public, m_public과 동일
		Base::m_protected = 123; 
		// Base::m_private; 
	}
};

class GrandChild : public Derived
{
public:
	GrandChild()
	{
		// Derived::m_public;
		// Derived::m_protected;
		// Derived::m_private;
	}
};

int main()
{
	Base base;

	base.m_public = 123;
	//base.m_protected = 123; 접근 불가

	Derived derived;


	return 0;
}