#include <iostream>

using namespace std;

/* Section06_07 �������� �⺻���� ���� */

/*
���������� '����' �޸𸮸� ����ϰ�, ���� �Ҵ� �޸𸮴� '��' �޸𸮸� �����
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
	cout << (int)&x << endl; // 10������ Ȯ��

	// * : de-reference operator
	// de-reference�� �����Ͱ� ���� �ּҿ����� �� �����Ͱ� �־�� ��� ���������� ����Ű�⸸ �ϴ� �Ϳ� ���ؼ�,
	// �ű⿡ ��¥ ���� �ִ��� ���������� �����Ͽ� �鿩�� ���ڴٴ� �ǹ�

	cout << *(&x) << endl;

	// �����ʹ� �ּҸ� �����ϴ� ����
	int *ptr_x;
	ptr_x = &x;

	// �̷��Ե� ����
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
	cout << sizeof(ptr_s) << endl; // ������ ������ ũ��� 32bit������ 4�� ����, 64bit������ 8

	return 0;
}