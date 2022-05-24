#include <iostream>

using namespace std;

/* Section09_05 증감 연산자 오버로딩 */

class Digit
{
private:
	int m_digit;

public:
	Digit(int digit = 0) :m_digit(digit) {}

	// prefix
	// prefix 연산자의 리턴타입은 l-value
	Digit& operator ++ ()
	{
		++m_digit;
		return *this;
	}

	// postfix 일 경우 파라미터로 더미를 추가
	// 리턴 타입만으로는 컴파일러가 두 연산자를 구별할 수가 없고 동일한 함수로 인식하기 때문
	// postfix 연산자의 리턴 타입은 r-value
	Digit& operator ++ (int)
	{
		Digit temp(m_digit);
		
		// 전위연산자 오버로딩을 해놓은 상태라 그것을 활용
		// *this는 자기자신의 포인터를 dereferencing 한 것, 즉 객체이기 때문
		++(*this); 
		return temp; // temp는 instance
	}

	friend ostream& operator << (ostream& out, const Digit& d)
	{
		out << d.m_digit;
		return out;
	}


};

int main()
{
	Digit d(5);
	cout << ++d << endl;
	cout << d << endl;
	cout << d++ << endl;
	cout << d << endl;

	return 0;
}