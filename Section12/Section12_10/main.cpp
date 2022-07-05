#include <iostream>
#include <string>
using namespace std;

/* Section12_10 동적 형변환 */

class Base
{
public:
	int m_i = 0;
	virtual void print()
	{
		cout << "i'm base" << endl;
	}
};

class Derived1 : public Base
{
public:
	int m_j = 1;
	virtual void print() override
	{
		cout << "i'm derived 1 " << endl;
	}
};

class Derived2 : public Base
{
public:
	string m_name = "dr. two";

	virtual void print() override
	{
		cout << "i'm derived 2" << endl;
	}
};

int main()
{
	Derived1 d1;
	Base* base = &d1;

	d1.m_j = 1024;

	auto* base_to_d1 = dynamic_cast<Derived1*>(base);
	cout << base_to_d1->m_j << endl;

	//*base_to_d1 = dynamic_cast<Derived2*>(base);
	//cout << base_to_d1->m_name << endl;

	// static cast는 런타임 관계없이 무조건 밀어붙이는 캐스팅
	//auto *base_to_d1 = static_cast<Derived2*>(base);
	//cout << base_to_d1->m_name << endl;





	return 0;
}