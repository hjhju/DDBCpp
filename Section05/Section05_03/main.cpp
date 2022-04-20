#include <iostream>
#include <cmath> // for sqrt()
using namespace std;

/* Section05_04 goto */ // 쓰는 일 거의 없음

int main()
{
	double x;
	
tryAgain : //label
	
	cout << "enter a non-negative number" << endl;
	cin >> x;

	if (x < 0.0)
		goto tryAgain;

	cout << sqrt(x) << endl;

	return 0;
}