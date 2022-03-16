#include <iostream>
#include <typeinfo>
#include <iomanip>
using namespace std;

/* Section04_05 : ����ȯ type conversion */


int main()
{
	cout << typeid(4.0).name() << endl; // double

	int a = 123;
	int b = 123.0;

	cout << typeid(a).name() << endl; // int
	cout << typeid(b).name() << endl; // int

	float c = 1.0f;
	double d = c; //numeric promotion -> ���� �ȵ�

	// numeric conversion
	int i = 30000;
	char j = i; // 30000�� char ������ ���� ����
	cout << static_cast<int>(j) << endl; // 48�� ����

	double l = 0.123456789;
	float f = l;
	int m = l;
	cout << std::setprecision(12) << f << endl << m << endl;

	cout << 5u - 10u;

	// �켱���� ���� ����
	// int, unsigned int,long, unsinged long, long long, unsinged long long, float, double, long double



	return 0;
}