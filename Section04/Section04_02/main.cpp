#include <iostream>

using namespace std;

/* Section04_02 : 전역변수, 정적변수, 내부연결, 외부연결 */

int value = 123;

// 전역변수에 static을 붙이면 다른 cpp파일에서 접근할수 없음, 영역이 제한됨
static int g_a = 1;


// forward declaration
extern void doSomething2();
extern int b; // 다른 파일에 있는 b변수의 메모리를 공유하겠다는 의미!!
// extern int b = 123; 처럼 쓰면 에러 // 이미 다른파일에서 초기화가 이루어졌기때문

void doSomething()
{
	// 변수 a가 os로 부터 받은 메모리가 static이라는 의미
	// 같은 변수 계속 쓰게 됨
	// static은 초기화시 선언을 같이 해줘야 사용가능!!
	// static이 없으면 변수 a는 영역 밖을 벗어나면 메모리 해제됨

	static int a = 1; 
	++a;
	++g_a;

	cout << a << endl;
}

int main()
{
	cout << value << endl;

	int value = 1; 

	cout << ::value << endl; // 전역변수 사용시 :: 붙임  :: 는 global scope operator
	cout << value << endl;

	doSomething(); // 2
	doSomething(); // 2 // 변수에 static을 붙이면 3이 나옴
	doSomething(); // 2 // 변수에 static을 붙이면 4이 나옴

	doSomething2();
	cout << b << endl;

	return 0;
}