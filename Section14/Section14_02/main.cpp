#include <iostream>

using namespace std;

/* Section14_02 예외처리와 스택 되감기 */

// void last() throw(int) exception specifier
// void last() throw(...) exception specifier

// throw() 로 ()안에 아무것도 안적으면 아무것도 던지지 않겠다는 의미임!
//void last() throw()
void last()
{
	cout << "last " << endl;
	cout << "Throws exception" << endl;

	// last()에서 던진 것이 int형이라 catch에서 int인것을 찾아서 날아감
	// 그 아래것들이 실행이 되지않음!!
	
	//throw - 1;
	throw - 1.0f;

	cout << "End last" << endl;
}

void third()
{
	cout << "Third" << endl;

	last();

	cout << "End Third" << endl;
}

void second()
{
	cout << "Second" << endl;

	try
	{
		third();
	}
	catch (double)
	{
		cerr << "Second caught int exception" << endl;
	}

	cout << "End Second" << endl;

}

void first()
{
	cout << "First" << endl;

	try
	{
		second();
	}
	catch (int)
	{
		cerr << "first caught int exception" << endl;
	}

	cout << "End First" << endl;

}

int main()
{
	cout << "Start" << endl;

	try
	{
		first();
	}
	catch (int)
	{
		cerr << "main caught int exception" << endl;
	}
	catch (...) // catch-all handlers
	{
		cerr << "main caught ellipses exception" << endl;
	}

	return 0;
}