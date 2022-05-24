#include <iostream>
#include <cassert>
using namespace std;

/* Section09_10 변환 생성자, explicit, delete */

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	// delete를 이용해서 막음
	Fraction(char) = delete;
	
	// explicit을 쓰면 converting constructor 못함
	explicit Fraction(int num = 0, int den = 1) :m_numerator(num), m_denominator(den)
	{
		assert(den != 0);
	}

	Fraction(const Fraction& fraction) // copy constructor
		:m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "Copy constructor called" << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Fraction& f)
	{
		cout << f.m_numerator << " / " << f.m_denominator << endl;
		return out;
	}
};

void doSomthing(Fraction frac)
{
	cout << frac << endl;
}


int main()
{
	Fraction frac(7);

	doSomthing(frac);
	
	// 아래도 가능 - converting constructor
	// explicit이 들어가면 불가!!
	//doSomthing(6);

	// delete로 인해 생성이 막힘
	// Fraction frac('c');

	return 0;
}