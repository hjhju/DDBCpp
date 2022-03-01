#include <iostream>

using namespace std;

/* Section04_01 : 지역변수, 범위, 지속기간 */

// 변수 이름이 중복될 때 범위나누고 namespace 지정해주면 됨
namespace work1
{
	int a = 1;
	void doSomething()
	{
		a += 3;
	}
}

// 컴파일러 c++17 에서 변경된 내용 
// nested namespace를 다음과 같이 표현 가능
namespace work2::work22::work222
{
	int a = 1;
	void doSomething()
	{
		a += 3;
	}
}

int main()
{
	int apple = 5;
	cout << apple << endl; //5

	// 중괄호로 영역 나눌 수 있음
	{
		int apple2 = 3;
		apple = 1;
		cout << apple << endl; //1
	}
	cout << apple << endl<<endl; //1
	// cout << apple2 << endl; //사용할 수 없음


	// 아래와 같이 namespace내 변수, 함수 접근 가능
	cout << work1::a << endl;
	work1::doSomething();
	cout << work1::a << endl;



	return 0;
}