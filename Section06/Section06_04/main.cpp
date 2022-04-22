#include <iostream>

using namespace std;

/* Section06_07 포인터의 기본적인 사용법 */

/*
지역변수는 '스택' 메모리를 사용하고, 동적 할당 메모리는 '힙' 메모리를 사용함
*/

struct Something
{
	int a, b, c, d;
};

int main()
{
	int x = 5;
	double d = 123.2;

	cout << x << endl;
	// & : address of operator
	cout << &x << endl; 
	cout << (int)&x << endl; // 10진수로 확인

	// * : de-reference operator
	// de-reference는 포인터가 저쪽 주소에가면 이 데이터가 있어요 라고 간접적으로 가리키기만 하는 것에 대해서,
	// 거기에 진짜 뭐가 있는지 직접적으로 접근하여 들여다 보겠다는 의미

	cout << *(&x) << endl;

	// 포인터는 주소를 저장하는 변수
	int *ptr_x;
	ptr_x = &x;

	// 이렇게도 가능
	typedef int* pint;
	pint ptr_y = &x, ptr_m = &x;

	cout << "address : " <<ptr_x<< ", value : " << *ptr_x << endl;
	cout << sizeof(x)<< ", "<<sizeof(ptr_x) << ", " << sizeof(&x) << endl;
	double *ptr_d = &d;
	cout << "address : " << ptr_d << ", value : " << *ptr_d << endl;
	cout << sizeof(d) << ", "<< sizeof(ptr_d) << ", " << sizeof(&d) << endl;


	Something s;
	Something* ptr_s;

	cout << sizeof(s) << endl; //16
	cout << sizeof(ptr_s) << endl; // 포인터 변수의 크기는 32bit에서는 4로 고정, 64bit에서는 8

	return 0;
}