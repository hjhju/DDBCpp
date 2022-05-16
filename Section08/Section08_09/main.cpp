#include <iostream>

using namespace std;

/* Section08_11 ���� ��� �Լ� */

class Something
{
	// Ŭ���� ���ο��� static ��� ������ �ʱ�ȭ �ϴ� ��� - 1) inner class ����
public:
	class _init
	{
	public:
		_init()
		{
			m_value = 9876;
		}
	};

private:
	static int m_value;
	int s_value = 120;
	// 2) inner class ����
	static _init s_initializer;

public:

	//�����ڿ��� static ������ �ʱ�ȭ ��ų�� ����!!
	//Something() : s_value(120), m_value(200) {}
	
	
	static int getValue() // ���� ��� �Լ�
	{
		// m_value�� �������� �޸𸮿� �����ϴϱ� ������ ����
		return m_value; 
				
		// static�� this�� ����!!!
		//return this->m_value;
		//return this->s_value;

		// this�� �����ؾ��ϴ� ��� ���� ���� �Ұ�! s_value�� �Ұ�!
		// return s_value;
	}

	int temp()
	{
		return this->m_value + this->s_value;
	}

};

int Something::m_value = 1024;

// 3)���� Ŭ���� ���� �ʱ�ȭ
Something::_init Something::s_initializer;


int main()
{

	cout << Something::getValue() << endl;

	Something s1, s2;
	cout << s1.getValue() << endl;
	//cout << s1.m_value << endl;
	cout << endl;

	// ��� �Լ� ������
	int (Something:: * fptr1)() = &Something::temp;

	// Ư�� �ν��Ͻ�, �� s2�� �־�� �۵� ��ų�� ����
	cout << (s2.*fptr1)() << endl;


	// ���� ��� �Լ��� ���
	int (* fptr2)() = &Something::getValue;

	cout << fptr2() << endl;



	return 0;
}