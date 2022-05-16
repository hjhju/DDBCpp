#include <iostream>

using namespace std;

/* Section08_13 익명 객체 */

class A
{
public:
	int m_value;

	A(const int& n_in): m_value(n_in)
	{
		cout << "Constructor" << endl;
	}
	~A()
	{
		cout << "Destructor" << endl;

	}
	void print()
	{
		cout << "Hello" << endl;
	}

	void printDouble()
	{
		cout << m_value*2 << endl;

	}
};

class Cents
{
private:
	int m_cents;
public:
	Cents(int cents) { m_cents = cents; }
	int getCents() const { return m_cents; }
};

Cents add(const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents() + c2.getCents());
}

int main()
{
	//A a;
	//a.print();
	//a.print();

	/* 출력 */
	// Constructor
	// Hello
	// Hello
	// Destructor

	//A().print();
	//A().print();

	/* 출력 */
	//Constructor
	//Hello
	//Destructor
	//Constructor
	//Hello
	//Destructor

	A a(1);
	a.printDouble();
	A(1).printDouble();

	/* 출력 */
	//Constructor
	//2
	//Constructor
	//2
	//Destructor
	//Destructor

	cout << endl;
	cout << add(Cents(6), Cents(8)).getCents() << endl;

	return 0;
}