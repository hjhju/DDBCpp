#include <iostream>
#include <array>
#include "Storage8.h"

using namespace std;
/* Section 13_05 클래스 템플릿 특수화 */

template<typename T>
class A
{
public:
	A(const T& input)
	{}

	void doSomething()
	{
		cout << typeid(T).name() << endl;
	}

	void test()
	{

	}
};

// 클래스 템플릿 특수화
template<>
class A<char> //char로 특수화 시킴
{
public:
	
	A(const char& input) 
	{}

	void doSomething()
	{
		cout << "Char type specialization" << endl;
	}

};


int main()
{
	A<int> a_int(1);
	A<double> a_double(3.14);
	A<char> a_char('a');

	a_int.doSomething();
	a_double.doSomething();
	a_char.doSomething();

	cout << endl;
	// Define a Storage8 for integers
	Storage8<int> intStorage;

	for (int count = 0; count < 8; ++count)
		intStorage.set(count, count);

	for (int count = 0; count < 8; ++count)
		cout << intStorage.get(count) << "\n";

	cout << "Sizeof Storage8<int> " << sizeof(Storage8<int>) << endl;
	cout << endl;

	Storage8<bool> boolStorage;

	for (int count = 0; count < 8; ++count)
		boolStorage.set(count, count & 3);

	for (int count = 0; count < 8; ++count)
		cout << (boolStorage.get(count)?"true":"false") << "\n";

	cout << "Sizeof Storage8<bool> " << sizeof(Storage8<bool>) << endl;

	return 0;
} 