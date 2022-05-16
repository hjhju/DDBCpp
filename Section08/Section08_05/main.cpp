#include <iostream>

using namespace std;

/* Section08_07 this �����Ϳ� ���� ȣ�� */

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
	// �� �ν��Ͻ��� �ڱ��� �����͸� �������ְ�, �ش� �����͸� ������ this �̿�
	Simple(int id)
	{
		setID(id);

		// setID(id);�� ���� �ǹ�
		//this->setID(id);
		//(*this).setID(id);

		cout << this << endl; // this�� �̿��Ͽ� �ڱ� �ڽ��� �ּ� ���
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

	// �۵�����
	// Simple::setID(&s2, 4) == s2.setID(4);
	// ���������δ� ���ڸ� ����

	cout << endl;

	Calc ca(10);
	/*ca.add(10);
	ca.sub(1);
	ca.mul(2);
	ca.print();*/

	// ����ȣ�� ����
	ca.add(10).sub(1).mul(2).print(); //add(10). �� �ڱ��ڽ��� return �ǹǷ�

	

	return 0;
}