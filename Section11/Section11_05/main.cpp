#include <iostream>

using namespace std;

/* Section11_05 ��Ӱ� ���� ������ */

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
		m_protected = 123; // protected�� �ۿ����� �ȵ����� �ڽ� Ŭ���������� ���ٰ���
		//m_private = 123; // private�� �ȵ�
	}
};
*/

class Derived : private Base
{
public:
	Derived()
	{
		Base::m_public; // this->m_public, m_public�� ����
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
	//base.m_protected = 123; ���� �Ұ�

	Derived derived;


	return 0;
}