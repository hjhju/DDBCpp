#include <iostream>

using namespace std;

/* Section08_12 친구 함수와 클래스 freind */


class B; // forward declaration (전방선언) 이 되어야 됨, 많이 쓰지는 않음

class A
{
private:
	int m_value = 1;
	
	friend void doSomething(A& a);
	friend void doSomething2(A& a, B& b);

	// for doSomething3
	friend class B; 

};

class B
{
private:
	int m_value = 3;

	friend void doSomething2(A& a, B& b);

public:
	void doSomething3(A& a)
	{
		cout << a.m_value << endl;
	}

};

void doSomething(A& a)
{
	// 클래스의 freind 함수이므로 private 멤버 접근 가능
	cout << a.m_value << endl;
}

void doSomething2(A& a, B& b)
{
	// 클래스의 freind 함수이므로 private 멤버 접근 가능
	cout << a.m_value << " "<<b.m_value<<endl;
}

int main()
{
	A a;
	doSomething(a);

	B b;

	doSomething2(a, b);

	b.doSomething3(a);

	return 0;
}