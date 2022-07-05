#include <iostream>
#include <vector>
#include <functional>
using namespace std;

/* Section12_09 객체 잘림과 reference wrapper */

class Base
{
public:
	int m_i = 0;
	virtual void print()
	{
		cout << "i'm base" << endl;
	}
};

class Derived : public Base
{
public:
	int m_j = 1;
	virtual void print() override
	{
		cout << "i'm derived" << endl;
	}
};

void doSomething(Base& b)
{
	b.print();
}

int main()
{
	Derived d;
	Base &b = d;

	b.print(); // 다형성!, derived
	
	Base c = d;
	c.print(); // base

	doSomething(d);
	cout << endl;

	Base a;

	// 포인터로 구현
	std::vector<Base*> my_vec;
	my_vec.push_back(&a);
	my_vec.push_back(&d);

	for (auto& ele : my_vec)
		ele->print();

	cout << endl;

	// reference로 구현
	std::vector<std::reference_wrapper<Base>> my_vec2;
	my_vec2.push_back(a);
	my_vec2.push_back(d);

	for (auto ele : my_vec2)
		ele.get().print(); // reference로 부터 가져와야되므로 get을 붙여줘야됨

	return 0;
}