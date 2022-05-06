#include <iostream>
#include <array>
#include <tuple>
using namespace std;

/* Section07_05 다양한 반환 값들 (값, 참조, 구조체, 튜플) */

std::tuple<int, double> getTuple()
{
	int a = 10;
	double d = 3.14;
	return std::make_tuple(a, d);
}

struct S
{
	int a, b, c, d;
};

S getStruct()
{
	S my_s{ 1,2,3,4 };
	return my_s;
}

int getValue(int x)
{
	int value = x * 2;
	return value;
}

int* allocateMemory(int size)
{
	return new int[size];
}

int& getValue2(int x)
{
	int value = x * 2;
	return value;
}

int& get(std::array<int, 100>& my_array, int ix)
{
	return my_array[ix];
}

int main()
{
	int value = getValue(3);

	// 이렇게 잘 하지 않음
	int* array = allocateMemory(1024);
	delete[] array;

	int &value2 = getValue2(5);
	cout << value2 << endl;
	cout << value2 << endl; // getValue2가 종료되면 값이 사라지므로 쓰레기 값이 나옴
	cout << endl;


	std::array<int, 100> my_array;
	my_array[30] = 10;
	cout << my_array[30] << endl;
	get(my_array, 30) = 1024;
	cout << my_array[30] << endl;
	cout << endl;


	S my_s = getStruct();
	cout << my_s.a << " " << my_s.b << endl;
	cout << endl;

	std::tuple<int, double> my_tp = getTuple();
	cout << std::get<0>(my_tp) << endl; //10
	cout << std::get<1>(my_tp) << endl; //3.14

	// c++17부터는 아래처럼 가능
	auto [a, d]= getTuple();
	cout << a << endl;
	cout << d << endl;

	return 0;
}