#include <iostream>

using namespace std;

/* Section06_11 �޸� ���� �Ҵ� new�� delete */

int main()
{
	// ���α׷����� �������� �Ҵ��ϴ� �޸𸮴� stack�� ��
	// �������� �Ҵ��� �޸𸮴� heap�� ��
	// int array[100000]; //stack

	int* ptr = new int;
	*ptr = 7;

	int* ptr2 = new int(10);

	cout << ptr << " "<<ptr2<< endl;
	cout << *ptr << " "<<*ptr2<<endl;

	delete ptr, ptr2;
	ptr = nullptr;

	cout << "after delete" << endl;
	if (ptr != nullptr)
	{
		cout << ptr << endl;
	}

	// memory leak
	while (true)
	{
		int* ptr = new int;
		cout << ptr << endl;
		delete ptr;
	}



	return 0;
}