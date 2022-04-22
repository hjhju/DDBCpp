#include <iostream>

using namespace std;

/* Section06_01 배열 기초 array */

#define NUM_STU 10000

struct Rectangle
{
	int length;
	int width;
};

enum StudentName
{
	JACK,
	DASH,
	VIOLET,
	NUM_STUDENT,
};

void doSomething(int arr[])
{
	cout << (int)&arr << endl;
	cout << (int)&arr[0] << endl;
	cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << sizeof(arr) << endl;

}

int main()
{
	int student_scores[5];

	cout << sizeof(student_scores) << endl;

	cout << sizeof(Rectangle) << endl;

	Rectangle rect_arr[10];
	cout << sizeof(rect_arr) << endl;

	// 최신버전에서 가능!
	int my_array[]{ 1,2,3 };

	for (int i = 0; i < 3; i++)
	{
		cout << my_array[i] << endl;
	}

	// 이렇게도 가능
	cout << my_array[JACK] << endl;
	for (int i = 0; i < NUM_STUDENT; i++)
	{
		cout << my_array[i] << endl;
	}

	int student[NUM_STU];
	cout << sizeof(student) << endl;

	const int num = 5;
	int student2[num];
	cout << sizeof(student2) << endl;
	cout << endl;


	cout << (int)&my_array << endl;
	cout << (int)&my_array[0] << endl;
	cout << my_array[0] << endl;
	cout << my_array[1] << endl;
	cout << sizeof(my_array) << endl;

	cout << endl;

	doSomething(my_array);

	return 0;
}