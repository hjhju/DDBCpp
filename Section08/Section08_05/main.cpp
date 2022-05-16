#include <iostream>

using namespace std;

/* Section08_07 this 포인터와 연쇄 호출 */

class Calc
{
private:
	int m_value;
public:
	Calc(int init_value) :m_value(init_value) {}

	Calc& add(int value) 
	{
		m_value += value;
		return *this;
	}

	Calc& sub(int value)
	{
		m_value -= value;
		return *this;
	}

	Calc& mul(int value)
	{
		m_value *= value;
		return *this;
	}

	void print()
	{
		cout << m_value << endl;
	}
};

class Simple
{
private:
	int m_id;
public:
	// 각 인스턴스가 자기의 포인터를 가지고있고, 해당 포인터를 보려면 this 이용
	Simple(int id)
	{
		setID(id);

		// setID(id);와 같은 의미
		//this->setID(id);
		//(*this).setID(id);

		cout << this << endl; // this를 이용하여 자기 자신의 주소 출력
	}
	void setID(int id) { m_id = id; }
	int getID() { return m_id; }
};

int main()
{
	Simple s1(1), s2(2);
	s1.setID(2);
	s2.setID(4);

	cout << &s1 << " "<<&s2<< endl;

	// 작동원리
	// Simple::setID(&s2, 4) == s2.setID(4);
	// 문법상으로는 후자만 가능

	cout << endl;

	Calc ca(10);
	/*ca.add(10);
	ca.sub(1);
	ca.mul(2);
	ca.print();*/

	// 연쇄호출 가능
	ca.add(10).sub(1).mul(2).print(); //add(10). 은 자기자신이 return 되므로

	

	return 0;
}