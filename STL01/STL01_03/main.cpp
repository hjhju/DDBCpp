#include <iostream>
#include <bitset>
#include <string>

/* std::bitset */
// bit�� �����ϴ� Ŭ����
// cout, cin���� ����� ����

using namespace std;

int main()
{
	bitset<8> b1;
	bitset<8> b2 = 0b11110000;

	cout << b1 << endl;
	cout << b2 << endl;

	/* �� ��Ʈ ���� �Լ� : set, reset, [], flip() */

	b1.set(); // ��� 1��
	cout << b1 << endl;

	b1.reset(); // ��� 0����
	cout << b1 << endl;

	b1.set(1); // 0000 0010
	cout << b1 << endl;

	b1[2] = 1; // 0000 0110
	cout << b1 << endl;

	b1[0].flip(); // 0000 0111
	cout << b1 << endl;

	/* ���� �Լ� : test, all, none, any, count */
	if (b1.test(1) == true) {}
	if (b1[1] == true) {}
	if (b1.none() == true) {}

	int n2 = b1.count(); // 0�� �ƴ� �� ����
	cout << n2 << endl;

	/* ��Ʈ ���� */
	bitset<8> b3 = 0b00001111;
	bitset<8> b4 = 0b11110000;
	bitset<8> b5 = b3 | b4;
	cout << b5 << endl;


	return 0;
}