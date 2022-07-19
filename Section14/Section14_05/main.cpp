#include <iostream>

using namespace std;

/* Section14_05 �Լ� try */

class A
{
private:
	int m_x;
public:
	A(int x) : m_x(x)
	{
		if (x <= 0)
			throw 1;
	}
};

class B :public A
{
public:
	//B(int x) : A(x)
	//{

	//}

	// �����ڿ��� try/catch�� ����ϴ� ��� 
	B(int x) try : A(x)
	{
		// do initialization
	}
	catch (...)
	{
		// throw�� ������ ���⼭�� �ѹ� ����
		cout << "Catch in B constructor " << endl;
		//throw;
	}

};

// function try�� ������ �Ʒ��� ���� (indent�� �����)
void doSomething()
try
{
	throw - 1;
}
catch (...)
{
	cout << "Catch in doSomething()" << endl;
}


int main()
{
	try
	{
		//doSomething();
		B b(0);
	}
	catch (...)
	{
		cout << "Catch in main()" << endl;
	}

	return 0;
}