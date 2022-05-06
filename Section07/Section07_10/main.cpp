#include <iostream>
#include <string>
#include <cassert> //assert.h
#include <array>

using namespace std;

/* Section07_13 방어적 프로그래밍 */
/* Section07_14 단언하기 assert */

void printValue(const array<int, 5> &my_array, const int& ix)
{
	assert(ix >= 0);
	assert(ix <= my_array.size() - 1);

	cout << my_array[ix] << endl;
}


int main()
{
	
	// semantic errors
	int x;
	cin >> x;
	if (x >= 5) // x>5가 되어야 됨
		cout << "x is greater than 5" << endl;


	// violated assumption
	string hello = "hello, my name is jack jack";
	cout << "input form 0 to " << hello.size() - 1 << endl;
	while (true)
	{
		int ix;
		cin >> ix;
		if (ix >= 0 && ix <= hello.size() - 1)
		{
			cout << hello[ix] << endl;
			break;
		}
		else
			cout << "Please try again" << endl;
	}
	


	// 단언하기 assert 
	// ()내부의 조건이 false면 작동
	// release 모드에서는 작동하지 않음
	const int number = 5;
	assert(number == 5);

	// static_assert는 변수가 const가 붙어야 쓸수 있음
	// 컴파일 단계에서 차단
	//static_assert(number == 4, "number should be 5"); 

	array<int, 5>my_array{ 1,2,3,4,5 };
	printValue(my_array, 0);




	return 0;
}