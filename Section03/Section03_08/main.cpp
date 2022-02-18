#include <iostream>
#include <bitset>
using namespace std;

/* ch03_08 ��Ʈ���� ������ */

int main()
{
	// << left shift
	// >> right shift
	// ~, &, |, ^

	unsigned int a = 3;
	cout << std::bitset<4>(a) << endl; // a�� 4��Ʈ 2������ ��ȯ�Ͽ� ����

	unsigned int b = a << 2; // left shift �������� ��ĭ ��
	cout << std::bitset<4>(b) << " " << b << endl<<endl;

	// 2�� ������
	cout << std::bitset<8>(a) << " " << a << endl;
	cout << std::bitset<8>(a << 1) << " " << (a << 1) << endl;
	cout << std::bitset<8>(a << 2) << " " << (a << 2) << endl;
	cout << std::bitset<8>(a << 3) << " " << (a << 3) << endl;
	cout << std::bitset<8>(a << 4) << " " << (a << 4) << endl << endl;

	b = 1024;
	// 2�� ������
	cout << std::bitset<16>(b) << " " << b << endl;
	cout << std::bitset<16>(b >> 1) << " " << (b >> 1) << endl;
	cout << std::bitset<16>(b >> 2) << " " << (b >> 2) << endl;
	cout << std::bitset<16>(b >> 3) << " " << (b >> 3) << endl;
	cout << std::bitset<16>(b >> 4) << " " << (b >> 4) << endl << endl;


	// ������ ǥ���� �Ҷ��� �տ� 0b�� �ٿ���
	unsigned int c = 0b1100;
	unsigned int d = 0b0110;

	cout << std::bitset<4>(c) << " " << c<< endl;
	cout << std::bitset<4>(~c) <<" "<<(~c)<< endl;
	cout << std::bitset<4>(c & d) << " " << (c & d) << endl; // bitwise AND
	cout << std::bitset<4>(c | d) << " " << (c | d) << endl; // bitwise OR
	cout << std::bitset<4>(c ^ d) << " " << (c ^ d) << endl; // bitwise XOR


	return 0;
}