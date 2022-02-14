#include <iostream>

using namespace std;

/* ch03_03 증감 연산자 */

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



	return 0;
}