#include <iostream>

using namespace std;

/* Section08_12 ģ�� �Լ��� Ŭ���� freind */


class B; // forward declaration (���漱��) �� �Ǿ�� ��, ���� ������ ����

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
	// Ŭ������ freind �Լ��̹Ƿ� private ��� ���� ����
	cout << a.m_value << endl;
}

void doSomething2(A& a, B& b)
{
	// Ŭ������ freind �Լ��̹Ƿ� private ��� ���� ����
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