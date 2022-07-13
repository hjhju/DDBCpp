#include <iostream>

using namespace std;

/* Section 13_08 멤버함수를 한번 더 템플릿화 하기 */

template <class T>
class A
{
private:
	T m_value;
public:
	A(const T& input) :m_value(input)
	{

	}

	template<typename TT>
	void doSomething(const TT & input)
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
		cout << (TT)m_value << endl;
	}

	template<typename TT>
	void doSomething2()
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
		cout << (TT)m_value << endl;
	}

	void print()
	{
		cout << m_value << endl;
	}

};

int main()
{
	A<int> a_int(123);
	a_int.print();

	// 파라미터로 자료형이 구분되면 <>를 빼도 된다!!
	a_int.doSomething<float>(12.3);
	a_int.doSomething(123.4);
	a_int.doSomething('a');

	a_int.doSomething(double());
	cout << endl;

	A<char> a_char('A');
	a_char.print();
	a_char.doSomething2<int>();

	return 0;
}