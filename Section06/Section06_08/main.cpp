#include <iostream>

using namespace std;

/* Section06_11 메모리 동적 할당 new와 delete */

int main()
{
	// 프로그램에서 정적으로 할당하는 메모리는 stack에 들어감
	// 동적으로 할당한 메모리는 heap에 들어감
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