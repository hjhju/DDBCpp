#include <iostream>

using namespace std;

/* Section09_01 산술 연산자 오버로딩 */

// 연산자 오버로딩 
// 1) 전역함수로 연산자 오버로딩
//   - Cents add(const Cents& c1, const Cents& c2) 형태
// 
// 2) 멤버함수로 연산자 오버로딩 : 멤버함수란 객체에서 호출할수 있는 함수
//   - Cents operator + (const Cents& c2)


class Cents
{
private:
	int m_cents;
public:
	Cents(int cents=0) { m_cents = cents; }

	// const 객체는 const 가 뒤에 붙은 멤버 함수만 호출할 수 있음
	int getCents() const { return m_cents; }

	int &getCents() { return m_cents; }

	//friend Cents operator + (const Cents& c1, const Cents& c2)
	//{
	//	return Cents(c1.getCents() + c2.getCents());
	//}


	// friend를 떼면 매개변수가 너무 많다는 오류가 뜸
	// 아래처럼 this 활용
	// 멤버함수를 호출한 당사자인 c1이 첫번째 피연사자 됨, c2가 파라미터로 넘어가서 두번째 피연산자로 동작

	// 연산자 중에서 =, [], (), -> 는 멤버 함수로만 오버로딩 가능!!
	Cents operator + (const Cents& c2)
	{
		return Cents(this->m_cents + c2.m_cents);
	}
		
};

// c_out은 바뀌는 값이므로 const가 되면 안됨
// c_out의 경우 메모리의 값이 바뀌어야 하므로 L-value로 작용
// 이에 따라 int& 함수 호출
void add(const Cents& c1, const Cents& c2, Cents& c_out)
{
	c_out.getCents() = c1.getCents() + c2.getCents();
}

Cents add(const Cents& c1, const Cents& c2)
{
	return Cents( c1.getCents() + c2.getCents());
}


int main()
{
	Cents cents1(6);
	Cents cents2(8);

	Cents sum;
	add(cents1, cents2, sum);

	cout << sum.getCents() << endl;

	cout << add(cents1, cents2).getCents() << endl;

	// 익명 object 사용 가능
	cout << (cents1 + cents2 + Cents(6) + Cents(10)).getCents() << endl;


	return 0;
}