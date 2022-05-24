#include <iostream>
#include <cassert>
using namespace std;

/* Section09_10 ��ȯ ������, explicit, delete */

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	// delete�� �̿��ؼ� ����
	Fraction(char) = delete;
	
	// explicit�� ���� converting constructor ����
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
	
	// �Ʒ��� ���� - converting constructor
	// explicit�� ���� �Ұ�!!
	//doSomthing(6);

	// delete�� ���� ������ ����
	// Fraction frac('c');

	return 0;
}