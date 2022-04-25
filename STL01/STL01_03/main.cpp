#include <iostream>
#include <bitset>
#include <string>

/* std::bitset */
// bit를 관리하는 클래스
// cout, cin으로 입출력 가능

using namespace std;

int main()
{
	bitset<8> b1;
	bitset<8> b2 = 0b11110000;

	cout << b1 << endl;
	cout << b2 << endl;

	/* 각 비트 접근 함수 : set, reset, [], flip() */

	b1.set(); // 모두 1로
	cout << b1 << endl;

	b1.reset(); // 모두 0으로
	cout << b1 << endl;

	b1.set(1); // 0000 0010
	cout << b1 << endl;

	b1[2] = 1; // 0000 0110
	cout << b1 << endl;

	b1[0].flip(); // 0000 0111
	cout << b1 << endl;

	/* 조사 함수 : test, all, none, any, count */
	if (b1.test(1) == true) {}
	if (b1[1] == true) {}
	if (b1.none() == true) {}

	int n2 = b1.count(); // 0이 아닌 것 개수
	cout << n2 << endl;

	/* 비트 연산 */
	bitset<8> b3 = 0b00001111;
	bitset<8> b4 = 0b11110000;
	bitset<8> b5 = b3 | b4;
	cout << b5 << endl;


	return 0;
}