#include <iostream>

using namespace std;

/* ch03_04 sizeof, comma 연산자, 조건부 연산자 */

int main()
{
	float a;
	cout << sizeof(a) << endl;

	// comma operator 
	// z = (a, b) 이면 b가 z에 대입됨
	int x = 3;
	int y = 10;
	int z = (++x, ++y);
	cout << x << " " << y << " " << z << endl;

	z = x, y; // = 연산자가 ,연산자 보다 우선순위가 높음
	cout << x << " " << y << " " << z << endl;

	// conditional operator
	bool onSale = true;
	const int price = (onSale==true)?10:100;
	cout << price << endl;

	cout << ((x % 2 == 0) ? "even" : "odd") << endl;


	return 0;
}