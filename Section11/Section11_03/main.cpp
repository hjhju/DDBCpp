#include <iostream>

using namespace std;

/* Section11_03 ������ Ŭ�������� ���� ���� */

class Mother
{
public:
	int m_i;

	Mother(const int &m_in=0) :m_i(m_in)
	{
		cout << "Mother" << endl;
	}
};

class Child :public Mother
{
public:
	double m_d;

public:
	Child() :m_d(1.0), Mother(1024) //: m_i(1024) Mother�� ������ inialized list ���·δ� �ʱ�ȭ �ȵ� 
	{
		cout << "Child" << endl;
	}
};

int main()
{
	Mother m1;
	cout << endl;
	Child c1; //mother���� ������
	
	return 0;
}