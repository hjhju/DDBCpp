#include <iostream>

using namespace std;

/* Section08_10 정적 멤버 변수 */

int generateID()
{
	static int s_id = 0; 
	return ++s_id;
}

class Something
{
public:
	static int m_value; // 정적 멤버 변수
	
	// const이면 여기서 값을 초기화 시켜줘야하고 다른 곳에서 변경 불가
	//static const int m_value = 1;

	// constexpr 이면 컴파일 타임에 이 값이 확정되어야 함
	// singleton 패턴에서 많이 사용되는 형태
	//static constexpr int m_value = 1;

};

// cpp 파일에 정의하는 것이 좋음, static을 헤더에 두면 컴파일 에러 뜸 !!
int Something::m_value = 1; 

int main()
{
	cout << generateID() << endl;
	cout << generateID() << endl;
	cout << generateID() << endl;
	cout << endl;

	cout << &Something::m_value << " " << Something::m_value << endl; // 주소 모두 동일

	Something st1;
	Something st2;

	st1.m_value = 2;

	cout << &st1.m_value << " " << st1.m_value << endl; // 2
	cout << &st2.m_value << " " << st2.m_value << endl; // 2

	Something::m_value = 1024; // 메모리에 정적으로 존재하는 존재므로 직접 접근하여 변경 가능

	cout << &Something::m_value << " " << Something::m_value << endl;


	return 0;
}