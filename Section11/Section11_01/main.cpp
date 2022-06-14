#include <iostream>

using namespace std;

/* Section11_01 상속의 기본 (1) */

class Mother
{
// protected를 쓰면 자식한테는 허용이 됨
//private:
protected:
	int m_i;
public:
	// default 생성자
	Mother() : m_i(0)
	{}

	Mother(const int& i_in) : m_i(i_in)
	{
		cout << "Mother constructor" << endl;
	}

	void setValue(const int& i_in)
	{
		m_i = i_in;
	}

	int getValue()
	{
		return m_i;
	}
};

// Mother은 generalized class라고도 함
// child는 mother의 것을 가져와서 쓸 수 있음
// child 자신만의 것을 구현할 수 있음
class Child : public Mother // derived class
{
private:
	double m_d;
public:
	Child(const int& i_in, const double& d_in) : Mother(i_in), m_d(d_in)
	{

	}

	void setValue(const int & i_in, const double& d_in)
	{
		Mother::setValue(i_in); // 아래와 같은 표현
		// m_i = i_in; // Mother에서 protected이므로 접근 가능

		m_d = d_in;

	}

	void setValue(const double& d_in)
	{
		m_d = d_in;
	}

	double getValue()
	{
		return m_d;
	}
};

class Daughter : public Mother
{

};

class Son : public Mother
{

};

int main()
{
	Mother mot;
	mot.setValue(1024);
	cout << mot.getValue() << endl;

	Child child(1024, 128);
	//child.Mother::setValue(1000);
	//child.setValue(128);
	cout << child.Mother::getValue() << endl;
	cout << child.getValue() << endl;

	return 0;
}