#include <iostream>
#include <typeinfo>
#include <iomanip>
using namespace std;

/* Section04_05 : 형변환 type conversion */


int main()
{
	cout << typeid(4.0).name() << endl; // double

	int a = 123;
	int b = 123.0;

	cout << typeid(a).name() << endl; // int
	cout << typeid(b).name() << endl; // int

	float c = 1.0f;
	double d = c; //numeric promotion -> 문제 안됨

	// numeric conversion
	int i = 30000;
	char j = i; // 30000은 char 범위에 들어가지 않음
	cout << static_cast<int>(j) << endl; // 48이 나옴

	double l = 0.123456789;
	float f = l;
	int m = l;
	cout << std::setprecision(12) << f << endl << m << endl;

	cout << 5u - 10u;

	// 우선순위 높은 순서
	// int, unsigned int,long, unsinged long, long long, unsinged long long, float, double, long double



	return 0;
}