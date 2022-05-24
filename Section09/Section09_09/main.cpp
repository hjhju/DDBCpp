#include <iostream>
#include <cassert>
using namespace std;

/* Section09_09 ���� ������, ���� �ʱ�ȭ ��ȯ�� ����ȭ */

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int num = 0, int den = 1) :m_numerator(num), m_denominator(den)
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

Fraction doSomthing()
{
	Fraction temp(1, 2); // �⺻ �����ڷ� ����
	return temp;
}

int main()
{
	Fraction frac(3, 5);

	Fraction fr_copy(frac); // copy

	Fraction fr_copy2 = frac; // copy initailize

	Fraction fr_copy3(Fraction(3, 10)); // copy�� �߻����� ���� - �����Ϸ��� �ʿ���ٰ� �Ǵ�

	cout << frac << " " << fr_copy << endl;
	cout << fr_copy2 << " " << fr_copy3 << endl;

	// debug������ copy�� �߻������� release ��忡���� �߻����� ����
	Fraction fr_copy4 = doSomthing(); 
	cout << fr_copy4 << endl; 

	return 0;
}