#include <iostream>

using namespace std;

/* Section12_02 가상함수와 다형성 */

class A
{
public:
	// 상속된 오버라이딩된 함수들에도 virtual 키워드를 추가하는 것이 좋음!!
	virtual void print() { cout << "A" << endl; }
};

class B: public A
{
public:
	void print() { cout << "B" << endl; }
};

class C : public B
{
public:
	void print() { cout << "C" << endl; }
};

class D : public C
{
public:
	void print() { cout << "D" << endl; }
};

int main()
{
	A a;
	//a.print();
	B b;
	//b.print();
	C c;
	//c.print();
	D d;
	//d.print();

	A& ref1 = b;
	ref1.print(); 

	A& ref2 = c;
	ref2.print(); 

	C& ref3 = d;
	ref3.print(); // D는 C의 직접적인 상속이지만 가장 상위클래스인 A의 virtual을 따라감

	return 0;
}