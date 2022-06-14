#include <iostream>

using namespace std;

/* Section11_01 ����� �⺻ (1) */

class Mother
{
// protected�� ���� �ڽ����״� ����� ��
//private:
protected:
	int m_i;
public:
	// default ������
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

// Mother�� generalized class��� ��
// child�� mother�� ���� �����ͼ� �� �� ����
// child �ڽŸ��� ���� ������ �� ����
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
		Mother::setValue(i_in); // �Ʒ��� ���� ǥ��
		// m_i = i_in; // Mother���� protected�̹Ƿ� ���� ����

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