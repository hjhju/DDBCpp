#include <iostream>
#include <cstddef>
using namespace std;

/* Section06_07 null pointer */

void doSomething(double *ptr)
{
	cout << "address of pointer variable of in doSomething() " << &ptr << endl;

	if (ptr != nullptr)
	{
		//do something useful
		cout<< *ptr << endl;
	}
	else
	{
		cout << "null ptr" << endl;
	}
}

void doSomething2(double* ptr)
{
	cout << "address of pointer variable of in doSomething2() " << &ptr << endl;

	if (ptr != nullptr)
	{
		//do something useful
		cout << *ptr << endl;
	}
	else
	{
		cout << "null ptr" << endl;
	}
}

int main()
{
	double *ptr1 = 0; // c-style
	double *ptr2 = nullptr; // modern c++

	doSomething(ptr1);
	doSomething2(ptr2);

	double d = 123.4;

	doSomething(&d);
	ptr1 = &d;

	doSomething2(ptr1);

	// nullptr_t nptr;

	cout << "address of pointer variable of in main() " << &ptr1 << endl;

	return 0;
}