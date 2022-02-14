#include <iostream>

using namespace std;

/* ch03_03 증감 연산자 */

int add(int x, int y)
{
	return x + y;
}

int main()
{
	int x = 5;
	int y = --x;
	int z = x--;

	cout << y << endl;
	cout << z << endl;

	int a = 6, b = 6;
	cout << a << " " << b << endl;
	cout << ++a << " " << --b << endl;
	cout << a << " " << b << endl;
	cout << a++ << " " << b-- << endl;
	cout << a << " " << b << endl;

	int c = 1, d = 2;
	int e = add(c, ++d); //4
	cout << e << endl;

	return 0;
}