#include <iostream>

using namespace std;

/* ch03_05 관계연산자 */

int main()
{
	/*
	int x, y;
	cin >> x >> y;
	cout << x << " " << y << endl;

	if (x == y)
		cout << "equal" << endl;
	if (x != y)
		cout << "Not equal" << endl;
	if (x < y)
		cout << "y is greater than x" << endl;
	if (x >= y)
		cout << "x is greater than y or equal to y" << endl;

	*/

	// d1과 d2는 같아보이지만 같지 않음!!
	double d1(100 - 99.99);
	double d2(10 - 9.99);

	cout << d1 << " " << d2 << endl;
	cout << std::abs(d1-d2) << endl;


	if (d1 == d2)
		cout << "equal" << endl;
	else
	{
		cout << "not equal" << endl;
		if (d1>d2)
			cout << "d1>d2" << endl;
		else
			cout << "d1<d2" << endl;
	}

	const double epsilon = 1e-10;
	if (std::abs(d1 - d2) < epsilon)
		cout << "equal" << endl;
	else
		cout << "not equal" << endl;



	return 0;
}