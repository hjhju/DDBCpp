#include <iostream>

using namespace std;

/* Section06_12 �޸� ���� �Ҵ� new�� delete */
/* Section06_13 �����Ϳ� const */

int main()
{
	int length;
	cin >> length;

	int* array = new int[length] {11, 22, 33, 44};

	array[0] = 1;
	array[1] = 2;

	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " " << (uintptr_t) & array[i] << endl;
	}

	delete[] array;

	int value = 5; 
	const int* ptr = &value;
	int value2 = 10;

	value = 6;
	//*ptr = 6; // �ȵ�!
	cout << *ptr << endl;
	ptr = &value2; //��
	cout << *ptr << endl;

	int const* ptr2 = &value;
	const int* const ptr3 = &value;
	cout << *ptr2 << endl;
	cout << *ptr3 << endl;

	ptr2 = &value2; // ��
	// ptr3 = &value2; //�ȵ�

	return 0;
}