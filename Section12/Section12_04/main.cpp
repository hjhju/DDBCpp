#include <iostream>

using namespace std;

/* Section12_04 가상 소멸자 */

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
	// 소멸자 호출 순서는 자식->부모
	//Derived derived2(5);

	// 다형성을 이용한 case
	// Base의 소멸자를 virtual로 바꾸니 위와 같이,
	// delete base를 할때 자식->부모 순으로 소멸자 호출됨
	Derived* derived = new Derived(5);
	Base* base = derived;
	delete base;



	return 0;
}