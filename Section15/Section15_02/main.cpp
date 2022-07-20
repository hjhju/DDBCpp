#include <iostream>

using namespace std;

/* Section15_02 오른쪽 값 참조 (r-value referecne) */

void doSomething(int &lef)
{
	cout << "L-value ref" << endl;
}

void doSomething(int&& ref)
{
	cout << "R-value ref" << endl;
}

int getResult()
{
	return 100 * 100;
}

int main()
{
	int x = 5;
	int y = getResult();
	// const는 이후에 값 수정 불가
	const int cx = 6;
	const int cy = getResult();

	// 주석처리 된것은 컴파일 안되는 것들
	
	/* L-value references (L-value에 대한 참조만 가질 수 있음!!) */
	// L-value는 메모리를 가짐

	int& lr1 = x; // modifiable l-values
	// int &lr2 = cx; // non-modifiable l-values
	// int &lr3 = 5; // R-values라서 넣을 수 없음

	const int& lr4 = x; // modifiable l-values
	const int& lr5 = cx; // non-modifiable l-values
	const int& lr6 = 5; // R-values


	/* R-value references (R-value에 대한 참조만 가질 수 있음!!) */
	// R-value는 메모리를 가지지 못함 ex) 리터럴
	
	//int &&rr1 = x; // modifiable l-values
	//int &&rr2 = cx; // non-modifiable l-values
	int &&rr3 = 5; // R-values

	// 5라는 값은 rr3로 이전하고 rr3로 값을 바꿀수 있음
	cout << rr3 << endl;
	rr3 = 10;
	cout << rr3 << endl;

	//const int&& rr4 = x; // modifiable l-values
	//const int&& rr5 = cx; // non-modifiable l-values
	const int&& rr6 = 5; // R-values

	// 사라질 값을 임시로 저장하는 용도
	int&& rrr = getResult();


	// L/R value references (doSomething 오버로딩)
	doSomething(x);  // L-value
	//doSomething(cx);
	doSomething(5);  // R-value
	doSomething(getResult()); // R-value



	return 0;
}