#include <iostream>

using namespace std;

/* Section12_04 ���� �Ҹ��� */

class Base
{
private:

public:
	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
private:
	int* m_array;

public:
	Derived(int length)
	{
		m_array = new int[length];
	}

	virtual ~Derived()
	{
		cout << "~Derived()" << endl;
		delete[] m_array;
	}
};


int main()
{
	// �Ҹ��� ȣ�� ������ �ڽ�->�θ�
	//Derived derived2(5);

	// �������� �̿��� case
	// Base�� �Ҹ��ڸ� virtual�� �ٲٴ� ���� ����,
	// delete base�� �Ҷ� �ڽ�->�θ� ������ �Ҹ��� ȣ���
	Derived* derived = new Derived(5);
	Base* base = derived;
	delete base;



	return 0;
}