#include <iostream>

using namespace std;

/* Section12_02 �����Լ��� ������ */

class A
{
public:
	// ��ӵ� �������̵��� �Լ��鿡�� virtual Ű���带 �߰��ϴ� ���� ����!!
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
	ref3.print(); // D�� C�� �������� ��������� ���� ����Ŭ������ A�� virtual�� ����

	return 0;
}