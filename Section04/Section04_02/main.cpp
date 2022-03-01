#include <iostream>

using namespace std;

/* Section04_02 : ��������, ��������, ���ο���, �ܺο��� */

int value = 123;

// ���������� static�� ���̸� �ٸ� cpp���Ͽ��� �����Ҽ� ����, ������ ���ѵ�
static int g_a = 1;


// forward declaration
extern void doSomething2();
extern int b; // �ٸ� ���Ͽ� �ִ� b������ �޸𸮸� �����ϰڴٴ� �ǹ�!!
// extern int b = 123; ó�� ���� ���� // �̹� �ٸ����Ͽ��� �ʱ�ȭ�� �̷�����⶧��

void doSomething()
{
	// ���� a�� os�� ���� ���� �޸𸮰� static�̶�� �ǹ�
	// ���� ���� ��� ���� ��
	// static�� �ʱ�ȭ�� ������ ���� ����� ��밡��!!
	// static�� ������ ���� a�� ���� ���� ����� �޸� ������

	static int a = 1; 
	++a;
	++g_a;

	cout << a << endl;
}

int main()
{
	cout << value << endl;

	int value = 1; 

	cout << ::value << endl; // �������� ���� :: ����  :: �� global scope operator
	cout << value << endl;

	doSomething(); // 2
	doSomething(); // 2 // ������ static�� ���̸� 3�� ����
	doSomething(); // 2 // ������ static�� ���̸� 4�� ����

	doSomething2();
	cout << b << endl;

	return 0;
}