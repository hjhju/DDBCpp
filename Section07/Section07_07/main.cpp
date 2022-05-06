#include <iostream>
#include <array>
#include <functional>
using namespace std;

/* Section07_09 �Լ� ������ */


bool isEven(const int& num)
{
	if (num % 2 == 0) return true;
	else return false;
}

bool isOdd(const int& num)
{
	if (num % 2 == 1) return true;
	else return false;
}

// �̷��� �ٿ����°� ����!!
//typedef bool (*check_fcn_t)(const int&);
using check_fcn_t = bool (*)(const int&);

//void printNum(const array<int, 10>& my_array, bool (*check_fcn)(const int&))
void printNum(const array<int, 10>& my_array, check_fcn_t check_fcn)
{
	for (auto element : my_array)
	{
		if (check_fcn(element))
			cout << element;
	}
	cout << endl;
}

// functional ����
void printNum2(const array<int, 10>& my_array, std::function<bool(const int&)> check_fcn)
{
	for (auto element : my_array)
	{
		if (check_fcn(element))
			cout << element;
	}
	cout << endl;
}


int func()
{
	return 5;
}

int goo()
{
	return 10;
}

int func2(int x)
{
	return x*3;
}

int main()
{
	func();

	int(*fcnptr)() = func; // �Լ��� �ּҰ��� ������

	cout << fcnptr() << endl; // 5

	fcnptr = goo;

	cout << fcnptr() << endl; // 10

	int(*fcnptr2)(int) = func2;

	cout << fcnptr2(2) << endl; // 6

	std::array<int, 10> my_array{ 0,1,2,3,4,5,6,7,8,9 };
	printNum(my_array, isEven);
	printNum(my_array, isOdd);


	//c++11 ���� ��밡��
	std::function<bool(const int&)> fcnptr3 = isEven;
	printNum2(my_array, fcnptr3);
	fcnptr3 = isOdd;
	printNum2(my_array, fcnptr3);



	return 0;
}