#include <iostream>
#include <string>
using namespace std;

/* Section08_04 ������ ��� �ʱ�ȭ ��� */
// ������ �ڿ� : �� ���̰� ��� �ʱ�ȭ ��ų�� ����

/* Section08_05 ���� ������ */
// ���� ������ : �����ڰ� �ٸ� �����ڸ� ����ϴ� ��

class B
{
private:
	int m_b;

public:
	B(const int& m_b_in) : m_b(m_b_in)
	{

	}
	int print()
	{
		return m_b;
	}
};

class Something
{
	// �����ڰ� �����Ҷ��� �����ڿ��� �ʱ�ȭ�� ������ �켱�õ�!!
private:
	int m_i = 10;
	double m_d =10.0;
	char m_c = 'f';
	int m_arr[5] = { 10,20,30,40,50 };
	B m_b{ 1024 };

public:
	Something() : m_i{ 1 }, m_d{ 3.14 }, m_c{ 'a' }, m_arr{ 1,2,3,4,5 }, m_b(m_i-1)
	{
		m_i = 2;
		m_d = 3.28;
		m_c = 'b';
	}

	void print()
	{
		cout << m_i << " " << m_d << " " << m_c <<endl;
		for (auto& e : m_arr)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << m_b.print() << endl;
	}
};

class Student
{
private:
	int m_id;
	string m_name;
public:

	// ��� 1
	// �ߺ� �ʱ�ȭ ���� ������ ���� ������ �ۼ� ����, ���� ������!! (c++11 ���ķ� ����)
	Student(const string& name_in) : Student(0, name_in)
	{

	}

	Student(const int& id_in, const string& name_in) : m_id(id_in), m_name(name_in)
	{
		
	}

	// ��� 2 (���� ���)
	// �ʱ�ȭ �ڵ带 �и� -> �� �����ڿ� init(0, name_in), init(id_in, name_in) �־� �ֱ�
	void init(const int& id_in, const string& name_in)
	{
		m_id = id_in;
		m_name = name_in;
	}

	void print()
	{
		cout << m_id << " " << m_name << endl;
	}
};

int main()
{
	Something sth;
	sth.print();
	cout << endl;

	Student stu1(11, "jack jack");
	stu1.print();

	Student stu2("kim");
	stu2.print();


	return 0;
}