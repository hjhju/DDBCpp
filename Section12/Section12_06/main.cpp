#include <iostream>

using namespace std;

/* Section12_06 ����(�Լ�) ǥ */

// virtual table

class Base
{
public :
	// FunctionPointer *_vptr;
	virtual void fun1() {};
	virtual void fun2() {};

};

class Der :public Base
{
public:
	// FunctionPointer *_vptr;
	virtual void fun1() {};
	virtual void fun3() {};

};

int main()
{
	Base my_base;
	//Baes������ �����Լ� ���̺� fun1(), fun2()�� ����
	//�ش� �Լ��� ���� Base Ŭ�������� ã�Ƽ� �����Ŵ



	return 0;
}