#include <iostream>

using namespace std;

/* Section06_04 배열과 선택정렬  */

/*                value   index
	3 5 2 1 4	   3->1	   0->3
	1 5 2 3 4	   5->2    1->2
	1 2 5 3 4      5->3    2->3
	1 2 3 5 4      5->4    3->4
	1 2 3 4 5	            
*/
void printArray(int array[], int length)
{
	for (int index = 0; index < length; index++)
	{
		cout << array[index];
	}
	cout << endl;
}

int main()
{
	const int length = 5;

	int array[length] = { 3, 5, 2, 1, 4 };
	
	printArray(array, length);
	for (int i = 0; i < length-1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < length; j++)
		{
			if (array[minIndex] > array[j])
			{
				minIndex = j;
			}
		}
		int temp = array[minIndex];
		array[minIndex] = array[i];
		array[i] = temp;
		printArray(array, length);
	}

	return 0;
}