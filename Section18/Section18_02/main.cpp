#include <iostream>
#include <iomanip>
using namespace std;

/* Section18_02 ostream으로 출력하기  */

int main()
{
	// setf와 unsetf로 출력 옵션 바꾸기
	/*
	cout.setf(std::ios::showpos); // +기호 출력
	cout << 108 << endl;
	cout << 200 << endl;

	cout.unsetf(std::ios::showpos); // +기호 없애기
	cout << 109 << endl;

	cout.unsetf(std::ios::dec); // 10진수 모드 끄기
	cout.setf(std::ios::hex); // 16진수 모드 켜기
	cout << 108 << endl;

	// 이렇게도 가능
	cout.setf(std::ios::hex, std::ios::basefield);
	cout << 108 << endl;

	cout << std::dec;
	cout << 200 << endl;

	cout.setf(std::ios::uppercase);
	cout<<std::hex;
	cout << 200 << endl;
	*/

	// boolalpha로 설정하면 true가 1이 아닌 true로 출력됨
	cout << std::boolalpha;
	cout << true << " " << false;

	// 정밀도 조정하기
	//cout << std::defaultfloat; // 기본 설정
	//cout << std::scientific << std::uppercase; // 지수승으로 표기
	cout << std::showpoint;  // 소수점이 나옴
	cout << std::setprecision(3) << 123.456 << endl;
	cout << std::setprecision(4) << 123.456 << endl;
	cout << std::setprecision(5) << 123.456 << endl;
	cout << std::setprecision(6) << 123.456 << endl;
	cout << std::setprecision(7) << 123.456 << endl;


	cout << -12345 << endl;
	cout.fill('*'); // 빈칸을 '*'로채워줌
	cout << std::setw(10) << -12345 << endl;
	cout << std::setw(10) << std::left << -12345 << endl;
	cout << std::setw(10) << std::right << -12345 << endl;
	cout << std::setw(10) << std::internal << -12345 << endl;



	return 0;
}