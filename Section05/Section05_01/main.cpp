#include <iostream>
#include <cstdlib> // for exit

using namespace std;

/* Section05_01 제어 흐름 개요 control flow */
/* Section05_02 조건문 if  */

// halt
// jump (goto, break, continue)
// conditional branches (if, switch)
// loops (while, do while, for)
// exceptions (try, catch, throw)

int min(int x, int y)
{
	return (x > y ? y : x);
}

int main()
{
	cout << "i love you" << endl;
	// 무조건 종료!, 디버깅 할때도 자주 사용
	// exit(0); 

	int x;
	cin >> x;


	if (x > 10)
	{
		cout << "greater than 10" << endl;
	}
	else if(x < 10)
	{
		cout << "less than 10" << endl;
	}
	else 
	{
		return 0; //종료
	}


	if (x = 0) //x가 0이 되고 if(0)이므로 실행이 안됨
		cout << x << endl;
	cout << x << endl;

	int a, b;
	cin >> a >> b;

	if (a > 0 && b > 0)
	{
		cout << "both are positive" << endl;
	}
	else if (a>0 || b>0)
	{
		cout << "one of the nubmer is positive" << endl;
	}
	else
	{
		cout << "neither number is positive" << endl;
	}


	int c = min(1, 3);
	cout << c << endl;

	return 0;
}