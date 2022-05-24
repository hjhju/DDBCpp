#include <iostream>

using namespace std;

/* Section09_05 ���� ������ �����ε� */

class Digit
{
private:
	int m_digit;

public:
	Digit(int digit = 0) :m_digit(digit) {}

	// prefix
	// prefix �������� ����Ÿ���� l-value
	Digit& operator ++ ()
	{
		++m_digit;
		return *this;
	}

	// postfix �� ��� �Ķ���ͷ� ���̸� �߰�
	// ���� Ÿ�Ը����δ� �����Ϸ��� �� �����ڸ� ������ ���� ���� ������ �Լ��� �ν��ϱ� ����
	// postfix �������� ���� Ÿ���� r-value
	Digit& operator ++ (int)
	{
		Digit temp(m_digit);
		
		// ���������� �����ε��� �س��� ���¶� �װ��� Ȱ��
		// *this�� �ڱ��ڽ��� �����͸� dereferencing �� ��, �� ��ü�̱� ����
		++(*this); 
		return temp; // temp�� instance
	}

	friend ostream& operator << (ostream& out, const Digit& d)
	{
		out << d.m_digit;
		return out;
	}


};

int main()
{
	Digit d(5);
	cout << ++d << endl;
	cout << d << endl;
	cout << d++ << endl;
	cout << d << endl;

	return 0;
}