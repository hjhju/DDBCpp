#include <iostream>
#include <complex>

/* std::complex */

// 복소수를 나타내는 템플릿
// double, float, long double 타입으로 주로 사용됨

using namespace std;

int main()
{
	complex<double> c1(1, 0);

	cout << c1 << endl;

	cout << c1.real() << endl;
	cout << c1.imag() << endl;

	complex<double> c2 = sin(c1);
	cout << c2 << endl;

	complex<float> c5(3); // 3, 0
	complex<float> c6(3, 1); //3, 1
	complex<float> c7(3if); // 0, 3 // 허수부 만들기

	cout << c5 << endl;
	cout << c6 << endl;
	cout << c7 << endl;

	return 0;
}


