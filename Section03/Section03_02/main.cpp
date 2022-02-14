#include <iostream>

using namespace std;

/* ch03_02 산술 연산자 */

int main()
{
	int x = 7;
	// int y = -x; //- x라고 작성하면 안됨
	int y = 4;
	int z = x % y;
	cout << x << " " << y <<  " " << z << endl;

	cout << x / y << endl;
	cout << float(x) / y << endl;
	cout << x / float(y) << endl;
	cout << float(x) / float(y) << endl;


	return 0;
}