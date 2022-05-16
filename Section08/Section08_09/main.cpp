#include <iostream>

using namespace std;

/* Section08_11 정적 멤버 함수 */

class Something
{
	// 클래스 내부에서 static 멤버 변수를 초기화 하는 방법 - 1) inner class 생성
public:
	class _init
	{
	public:
		_init()
		{
			m_value = 9876;
		}
	};

private:
	static int m_value;
	int s_value = 120;
	// 2) inner class 생성
	static _init s_initializer;

public:

	//생성자에서 static 변수는 초기화 시킬수 없음!!
	//Something() : s_value(120), m_value(200) {}
	
	
	static int getValue() // 정적 멤버 함수
	{
		// m_value는 정적으로 메모리에 존재하니까 접근이 가능
		return m_value; 
				
		// static은 this를 못씀!!!
		//return this->m_value;
		//return this->s_value;

		// this로 접근해야하는 모든 것이 접근 불가! s_value도 불가!
		// return s_value;
	}

	int temp()
	{
		return this->m_value + this->s_value;
	}

};

int Something::m_value = 1024;

// 3)정적 클래스 변수 초기화
Something::_init Something::s_initializer;


int main()
{

	cout << Something::getValue() << endl;

	Something s1, s2;
	cout << s1.getValue() << endl;
	//cout << s1.m_value << endl;
	cout << endl;

	// 멤버 함수 포인터
	int (Something:: * fptr1)() = &Something::temp;

	// 특정 인스턴스, 즉 s2가 있어야 작동 시킬수 있음
	cout << (s2.*fptr1)() << endl;


	// 정적 멤버 함수의 경우
	int (* fptr2)() = &Something::getValue;

	cout << fptr2() << endl;



	return 0;
}