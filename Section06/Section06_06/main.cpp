#include <iostream>

using namespace std;

/* Section06_08 �����Ϳ� ���� �迭 */
/* Section-6_09 ������ ����� �迭 �ε��� */

struct MyStruct
{
	int array[5] = { 9 ,7, 5, 3, 1 };
};

void doSomething1(MyStruct *ms)
{
	cout << (*ms).array[0]<< " "<< sizeof((*ms).array) << endl;
}

void doSomething2(MyStruct ms)
{
	cout << ms.array[0] << " " << sizeof(ms.array) << endl;
}


// �����ͷ� ����
// void printArray(int *array) �� ����
void printArray(int array[]) 
{
	cout << sizeof(array) << endl; //4
	
	*array = 100;
}

int main()
{
	int array[5] = { 9, 7, 5, 3, 1 };

	cout << &(array[0]) << endl;
	cout << array << endl;
	cout << *array << endl;
	cout << sizeof(array) << endl; //20

	int* ptr = array;
	cout << ptr << endl;
	cout << *ptr << endl;
	cout << sizeof(ptr) << endl; // ������ ���� ��ü�� ����� 32bit���� 4

	printArray(array);

	cout << array[0] << " " << *array << endl; // 100�� ��
	cout << *ptr << " " << *(ptr + 1) << endl; // 100 7


	MyStruct ms;
	cout << ms.array[0] << endl;

	doSomething1(&ms);
	doSomething2(ms);

	cout << endl;

	// ������ �������� �迭 �ε���
	for (int i = 0; i < 5; i++)
	{
		cout << array[i] << " " << (uintptr_t) & array[i] << endl;
	}

	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << *(ptr+i) << " " << (uintptr_t)(ptr + i) << endl;
	}

	cout << endl;

	char name[] = "Jack jack";
	const int n_name = sizeof(name) / sizeof(char);

	for (int i = 0; i < n_name; ++i)
	{
		cout << *(name + i) << " ";
	}


	return 0;
}