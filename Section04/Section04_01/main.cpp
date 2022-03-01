#include <iostream>

using namespace std;

/* Section04_01 : ��������, ����, ���ӱⰣ */

// ���� �̸��� �ߺ��� �� ���������� namespace �������ָ� ��
namespace work1
{
	int a = 1;
	void doSomething()
	{
		a += 3;
	}
}

// �����Ϸ� c++17 ���� ����� ���� 
// nested namespace�� ������ ���� ǥ�� ����
namespace work2::work22::work222
{
	int a = 1;
	void doSomething()
	{
		a += 3;
	}
}

int main()
{
	int apple = 5;
	cout << apple << endl; //5

	// �߰�ȣ�� ���� ���� �� ����
	{
		int apple2 = 3;
		apple = 1;
		cout << apple << endl; //1
	}
	cout << apple << endl<<endl; //1
	// cout << apple2 << endl; //����� �� ����


	// �Ʒ��� ���� namespace�� ����, �Լ� ���� ����
	cout << work1::a << endl;
	work1::doSomething();
	cout << work1::a << endl;



	return 0;
}