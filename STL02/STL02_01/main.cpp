#include <iostream>
#include <cstring> // for strch()

using namespace std;

/* make find algorithm */

// 부분 문자열에서의 검색
// 시작주소와 마지막 요소의 주소 전달
// 검색 대상 : [first, last)
// 모든 배열로 부터 선형 검색을 수행 할수 있도록 하기위해 함수 템플릿 사용!!

// template<typename T>
// T* efind(T* first, T* last, T* vlaue)
template<typename T1, typename T2>
T1 efind(T1 first, T1 last, T2 vlaue)
{
	while (first != last && *first != vlaue)
	{
		++first;
	}
	return first;
}

int main()
{
	char s[] = "abcdefg";

	// c언어의 strch() 함수
	// 문자열에서 문자를 검색, 문자열의 시작 주소를 받아서 널문자('\0')를 받을때 까지 검색
	// 구간 종료 조건이 널문자도 검색 대상에 포함, 실패시 null 포인터 반환
	char* p = strchr(s, 'c');

	if (p == 0)
		cout << "fail" << endl;
	else
		cout << "success : " << *p << endl;


	char* p2 = efind(s, s + 4, 'f');
	if (p2 == 0)
		cout << "fail" << endl;
	else
		cout << "success : " << *p2 << endl;

	double x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	// 첫번째 두번쨰가 double에대한 포인터이므로 마지막도 double로 넣어줘야됨 7이라고 쓰면 오류뜸
	// template<typename T1, typename T2> 로 해서 구간의 타입과 검색할 요소의 타입을 다른 타입을 사용하면 됨!!
	// 구간의 시작과 마지막을 전달 받을때 포인터(*)표기를 하지 않음!!
	// 변경된 efind 참고!
	double* p3 = efind(x, x + 5, 11);  
	if (p3 == x+5)
		cout << "fail" << endl;



	return 0;
}