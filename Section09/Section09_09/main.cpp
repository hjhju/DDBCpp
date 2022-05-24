#include <iostream>
#include <cassert>
using namespace std;

/* Section09_09 복사 생성자, 복사 초기화 반환값 최적화 */

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
	Fraction temp(1, 2); // 기본 생성자로 생성
	return temp;
}

int main()
{
	Fraction frac(3, 5);

	Fraction fr_copy(frac); // copy

	Fraction fr_copy2 = frac; // copy initailize

	Fraction fr_copy3(Fraction(3, 10)); // copy가 발생하지 않음 - 컴파일러가 필요없다고 판단

	cout << frac << " " << fr_copy << endl;
	cout << fr_copy2 << " " << fr_copy3 << endl;

	// debug에서는 copy가 발생하지만 release 모드에서는 발생하지 않음
	Fraction fr_copy4 = doSomthing(); 
	cout << fr_copy4 << endl; 

	return 0;
}