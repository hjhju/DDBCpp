#include <iostream>

using namespace std;

/* Section11_07 상속받은 함수를 오버라이딩 하기 */

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

	friend std::ostream& operator <<(std::ostream& out, const Base& b)
	{
		out << "This is base output" << endl;
		return out;
	}
};

class Derived : public Base
{
private:
	double m_d;

public:
	Derived(int value) : Base(value)
	{

	}
	void print()
	{
		Base::print();
		cout << "i'm derived" << endl;
	}

	friend std::ostream& operator <<(std::ostream& out, const Derived& b)
	{
		cout << static_cast<Base> (b);
		out << "This is derived output" << endl;
		return out;
	}

};

int main()
{
	Base base(5);
	base.print();
	cout << base;

	Derived derived(7);
	derived.print();
	cout << derived;

	return 0;
}