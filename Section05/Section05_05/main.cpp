#include <iostream>

using namespace std;

/* Section05_07 �ݺ��� for */

int pow(int base, int exponent)
{
	int result = 1;
	for (int count = 0; count < exponent; ++count)
		result *= base;
	return result;
}

int main()
{
	int count = 0;
	for (; count < 10; count++)
	{
		cout << count << endl;
	}
	cout << count << endl;

	/* ���ǹ��� ���������� ���� ���� ��
	count = 0;
	for (; ; count++)
	{
		cout << count << endl;
	}
	cout << count << endl;
	*/

	cout << pow(2, 1) << endl;
	cout << pow(2, 4) << endl;

	// overflow �߻�
	/*
	for (unsigned int i = 9; i >= 0; --i)
		cout << i << endl;
	*/

	return 0;
}