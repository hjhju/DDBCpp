#include <iostream>

using namespace std;

/* Section06_12 ¸Ş¸ğ¸® µ¿Àû ÇÒ´ç new¿Í delete */
/* Section06_13 Æ÷ÀÎÅÍ¿Í const */

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
	//*ptr = 6; // ¾ÈµÊ!
	cout << *ptr << endl;
	ptr = &value2; //µÊ
	cout << *ptr << endl;

	int const* ptr2 = &value;
	const int* const ptr3 = &value;
	cout << *ptr2 << endl;
	cout << *ptr3 << endl;

	ptr2 = &value2; // µÊ
	// ptr3 = &value2; //¾ÈµÊ

	return 0;
}