#include <iostream>

using namespace std;

/* ch03_04 sizeof, comma ������, ���Ǻ� ������ */

int main()
{
	float a;
	cout << sizeof(a) << endl;

	// comma operator 
	// z = (a, b) �̸� b�� z�� ���Ե�
	int x = 3;
	int y = 10;
	int z = (++x, ++y);
	cout << x << " " << y << " " << z << endl;

	z = x, y; // = �����ڰ� ,������ ���� �켱������ ����
	cout << x << " " << y << " " << z << endl;

	// conditional operator
	bool onSale = true;
	const int price = (onSale==true)?10:100;
	cout << price << endl;

	cout << ((x % 2 == 0) ? "even" : "odd") << endl;


	return 0;
}