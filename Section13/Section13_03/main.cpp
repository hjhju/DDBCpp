#include "MyArray.h"

/* Section 13_03 �ڷ����� �ƴ� ���ø� �Ű����� */

int main()
{
	MyArray<double, 100> my_array;

	for (int i = 0; i < my_array.getLength(); ++i)
	{
		my_array[i] = i * 0.5;
		//my_array[i] = i + 65;
	}
	my_array.print();

	return 0;
}