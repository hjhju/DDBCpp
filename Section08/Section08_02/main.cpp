#include <iostream>

using namespace std;

/* Section08_03 생성자 Constructors */

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	// 생성자 : 클래스명과 동일하고 반환값이 없음
	// constructor 될때 자동으로 호출되는 함수

	// 기본 생성자
	Fraction()
	{
		m_numerator = 1;
		m_denominator = 1;
	}


	Fraction(const int &num_in, const int &den_in=1)
	{
		m_numerator = num_in;
		m_denominator = den_in;

		cout << "Fraction() constructor" << endl;
	}

	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

class Second
{
public:
	Second()
	{
		cout << "class Second() constructor" << endl;
	}
};


class First
{
	Second sec;

public:
	First()
	{
		cout << "class Second() constructor" << endl;
	}
};


int main()
{
	//Fraction frac;
	//frac.print();

	Fraction one_thirds(1, 3);
	one_thirds.print();

	Fraction one(1);
	one.print();

	// 주의!! 파라미터가 하나도 없는 생성자를 사용할때는 ()를 빼야됨
	// 클래스에 기본 생성자를 만들어줬기에 이렇게 사용 가능
	Fraction frac; 
	frac.print();

	Fraction two_thirds = Fraction{ 2, 3 };
	two_thirds.print();

	// 클래스안에 클래스가 들어있는 경우
	// second가 먼저 생성된 후 first가 생성됨!!
	First fir; 



	return 0;
}