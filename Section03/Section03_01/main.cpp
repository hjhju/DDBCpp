#include <iostream>
#include <cmath>

using namespace std;

/* ch03_01 연산자 우선순위와 결합 법칙 */

int main()
{
	int x = 4 + 2 * 3;
	int y = std::pow(2, 3);

	cout << x << " " << y << endl;

	int r = 1 + 2 + 3 * 4; //15
	cout << r << endl; 

	x = y = r; // 15 15 15
	cout << x << " " << y << " " << r << endl;
	
	x = 19;
	x /= --y + 5; // x = 1 y = 14
	cout << x << " " << y << endl;

	cout << (x || y && r || y) << endl;

	return 0;
}