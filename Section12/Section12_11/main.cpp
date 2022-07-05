#include <iostream>

using namespace std;

/* Section12_11 유도 클래스에서 출력 연산자 사용하기 */

class Base
{
public:
	Base() { }

	// virtual 함수를 통해 자식에서 수행하도록 함
	friend std::ostream& operator << (std::ostream& out, const Base& b)
	{
		return b.print(out);
	}

	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Base";
		return out;
	}
};

class Derived: public Base
{
	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Derived";
		return out;
	}
};

int main()
{
	Base b;
	cout << b << endl;

	Derived d;
	cout << d << endl;

	Base& bref = d;
	cout << bref << endl;



	return 0;
}