#include <iostream>

using namespace std;

/* Section14_05 함수 try */

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

	// 생성자에서 try/catch를 사용하는 경우 
	B(int x) try : A(x)
	{
		// do initialization
	}
	catch (...)
	{
		// throw가 없지만 여기서도 한번 잡음
		cout << "Catch in B constructor " << endl;
		//throw;
	}

};

// function try의 구조는 아래와 같다 (indent가 사라짐)
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