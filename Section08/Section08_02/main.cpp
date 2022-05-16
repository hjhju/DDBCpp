#include <iostream>

using namespace std;

/* Section08_03 ������ Constructors */

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	// ������ : Ŭ������� �����ϰ� ��ȯ���� ����
	// constructor �ɶ� �ڵ����� ȣ��Ǵ� �Լ�

	// �⺻ ������
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

	// ����!! �Ķ���Ͱ� �ϳ��� ���� �����ڸ� ����Ҷ��� ()�� ���ߵ�
	// Ŭ������ �⺻ �����ڸ� �������⿡ �̷��� ��� ����
	Fraction frac; 
	frac.print();

	Fraction two_thirds = Fraction{ 2, 3 };
	two_thirds.print();

	// Ŭ�����ȿ� Ŭ������ ����ִ� ���
	// second�� ���� ������ �� first�� ������!!
	First fir; 



	return 0;
}