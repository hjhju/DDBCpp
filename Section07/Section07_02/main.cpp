#include <iostream>

using namespace std;

/* Section07_04 주소에 의한 인수 전달 (call by adress)  */

// C 스타일 코딩 !
void foo2(int* arr, int length)
{
	for (int i = 0; i < length; i++)
		cout << arr[i] << endl;
	arr[0] = 10;
}

// 주소값 전달
void foo(int* ptr)
{
	cout << *ptr << " " << ptr<< " " <<& ptr << endl;
	*ptr = 10; // const 붙으면 안됨
}

void getSinCos(const double degrees, double *sin_out, double *cos_out)
{
	static const double pi = 3.141592 / 180.0;
	const double radians = degrees * pi;
	*sin_out = std::sin(radians);
	*cos_out = std::cos(radians);
}

int main()
{
	int value = 5;
	cout << value << " " << &value << endl;

	int* ptr = &value;
	cout << &ptr << endl;

	foo(ptr);
	foo(&value);
	//foo(5);
	cout << endl;

	double sin(0.0);
	double cos(0.0);

	// sin과 cos 의 주소를 넘겨서 getSinCos 함수의 매개변수인 포인터 sin_out, cos_out 이 각각 sin과 cos 의 주소를 가리키게 됨
	// 이를 통하여 간접 참조로 값을 바꿨으니 주소의 주인공인 sin과 cos 의 값이 바뀌게 됨
	// *이 포인터 변수에 붙으면 간접참조가 됨 (포인터 변수값인 주소값으로 찾아가면 있는 데이터값)
	getSinCos(30.0, &sin, &cos);
	cout << sin << " " << cos << endl;
	cout << endl;

	int arr[4]{ 1,2,3,4 };
	foo2(arr, 4);
	for (int i = 0; i < 4; i++)
		cout << arr[i] << endl;



	return 0;
}