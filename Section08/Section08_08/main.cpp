#include <iostream>

using namespace std;

/* Section08_10 ���� ��� ���� */

int generateID()
{
	static int s_id = 0; 
	return ++s_id;
}

class Something
{
public:
	static int m_value; // ���� ��� ����
	
	// const�̸� ���⼭ ���� �ʱ�ȭ ��������ϰ� �ٸ� ������ ���� �Ұ�
	//static const int m_value = 1;

	// constexpr �̸� ������ Ÿ�ӿ� �� ���� Ȯ���Ǿ�� ��
	// singleton ���Ͽ��� ���� ���Ǵ� ����
	//static constexpr int m_value = 1;

};

// cpp ���Ͽ� �����ϴ� ���� ����, static�� ����� �θ� ������ ���� �� !!
int Something::m_value = 1; 

int main()
{
	cout << generateID() << endl;
	cout << generateID() << endl;
	cout << generateID() << endl;
	cout << endl;

	cout << &Something::m_value << " " << Something::m_value << endl; // �ּ� ��� ����

	Something st1;
	Something st2;

	st1.m_value = 2;

	cout << &st1.m_value << " " << st1.m_value << endl; // 2
	cout << &st2.m_value << " " << st2.m_value << endl; // 2

	Something::m_value = 1024; // �޸𸮿� �������� �����ϴ� ����Ƿ� ���� �����Ͽ� ���� ����

	cout << &Something::m_value << " " << Something::m_value << endl;


	return 0;
}