#include <iostream>

using namespace std;

/* Section12_06 가상(함수) 표 */

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
	//Baes에대한 가상함수 테이블에 fun1(), fun2()가 있음
	//해당 함수의 것을 Base 클래스에서 찾아서 실행시킴



	return 0;
}