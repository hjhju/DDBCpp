#include <iostream>

using namespace std;

/* Section11_04 ������ Ŭ�������� ������ �ʱ�ȭ */

class Mother
{
private:
	int m_i;

public:
	Mother(const int& m_in = 0) :m_i(m_in)
	{
		cout << "Mother" << endl;
	}
};

class Child :public Mother
{
public:
	double m_d;

public:
	Child() :m_d(1.0), Mother(1024)
	{
		cout << "Child" << endl;
	}
};


class A
{
public:
	A(int a)
	{
		cout << "A: " << a << endl;
	}
	~A()
	{
		cout << "Destructor A" << endl;
	}
};

class B : public A
{
public:
	B(int a, double b) : A(a)
	{
		cout << "B: " << b << endl;
	}

	~B()
	{
		cout << "Destructor B" << endl;
	}
};

class C : public B
{
public:
	C(int a, double b, char c) : B(a,b)
	{
		cout << "C: " << c << endl;
	}

	~C()
	{
		cout << "Destructor C" << endl;
	}
};

int main()
{
	Child c1;

	cout << sizeof(Mother) << endl;
	cout << sizeof(Child) << endl; // MotherŬ������ �͵� ������ �ֵ��� ũ�� �Ҵ����

	cout << endl << endl;

	C c(1024, 3.14, 'a'); // �Ҹ��ڴ� C, B, A ������ �����

	return 0;
}