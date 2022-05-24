#include <iostream>

using namespace std;

/* Section09_03 단항 연산자 오버로딩 */

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	friend std::ostream& operator << (std::ostream& out, const Cents& cents)
	{
		out << cents.m_cents;
		return out;
	}

	Cents operator - () const
	{
		return Cents(-m_cents);
	}

	bool operator ! () const
	{
		return (m_cents == 0) ? true : false;
	}


};

int main()
{
	Cents cents1(6), cents2(8);

	// 단항연산자
	int a = 3;

	//cout << -a << endl;
	cout << cents1 << endl;
	cout << -cents1 << endl;
	cout << -Cents(-10) << endl;

	//cout << !a << endl;
	auto temp = !cents1; // bool로 잡음
	cout << temp << endl;
	cout << !Cents(8) << endl;
	cout << !Cents(0) << endl;

	return 0;
}