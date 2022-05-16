#include <iostream>
#include <string>
using namespace std;

/* Section08_09 Ŭ������ const */

class Something
{
public:
	int m_id = 0;

	Something(const Something& st_in)
	{
		m_id = st_in.m_id;

		cout << "Copy Constructor " << endl;
	}

	Something()
	{
		cout << "Constructor " << endl;
	}

	void setID(int id) { m_id = id; }

	int getID() const
	{ 
		return m_id;
	}
};

class Something2
{
public:
	string m_value = "default";

	// const�� �������� �����ε� ����!!

	const string& getValue() const 
	{
		cout << "const ver" << endl;
		return m_value; //const reference�� ����
	}

	string& getValue()
	{
		cout << "non-const ver" << endl;
		return m_value; //non-const reference�� ����
	}
};

// �Ű������� �����Ǿ� ���� ���� copy constructor�� �����
// �� st�� ����Ǿ� ��

// const Something &st�� ��� ����� �Ͼ�� ���� - �ּҰ��� ����
void print(const Something &st)
//void print(Something st)
{
	cout << &st << endl;

	cout << st.m_id << endl;
}

int main()
{
	//Something something;

	const Something something;

	// ��ü ������ const�� ���̸� �Ʒ� �ڵ�� ������ ��
	// something�� const�� ����ٴ� ���� m_id�� const�� ����Ͱ� ���� ȿ��
	// m_id�� ���� �ٲٷ��� setID�� ȣ���� ���� ����
	
	//something.setID(3);

	// ��� �Լ��� const�� ���̸� �Ʒ� �ڵ�� ����
	cout << something.getID() << endl;

	cout << &something << endl;

	print(something);

	cout << endl;

	Something2 some1;
	some1.getValue();
	some1.getValue() = 10;


	const Something2 some2;
	some2.getValue();
	// some2.getValue() = 20; // �ȵ�!


	return 0;
}