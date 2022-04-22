#include <iostream>

using namespace std;

/* Section06_10 c언어 스타일의 문자열 심볼릭 상수 */

const char *getName()
{
	return "Jack jack";
}

int main()
{
	// 포인터 변수에 리터럴를 담을 수는 없음
	// char* name = "Jack jack"; 
	// const를 붙여야만 기호적 상수처럼 사용할 수 있음
	const char *name = "Jack jack";
	const char *name2 = getName();

	cout << (uintptr_t)name << endl; // 같은 문자열이면 같은 주소값 출력
	cout << (uintptr_t)name2 << endl;


	int int_arr[5] = { 1, 2, 3, 4, 5 };
	char char_Arr[] = "hello world";
	const char* name3 = "kim jack";

	cout << int_arr << endl; //주소가 출력
	cout << char_Arr << endl; // 문자열이 출력
	cout << name3 << endl; // 문자열이 출력

	// cout은 문자열을 특별하게 출력


	return 0;
}