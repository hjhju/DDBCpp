#include <iostream>

using namespace std;

/* Section07_08 �Ű������� �⺻�� */

void print(int x = 0)
{
	cout << x << endl;
}

// �⺻���� �����ʼ����� ä�����ߵ�, �Ʒ��� ������
//void print2(int x = 0, int y, int z=30)

void print2(int x, int y = 20, int z = 30); // in header !!

void print2(int x, int y, int z )
{
	cout << x << " "<<y<<" "<<z<<endl;
}

int main()
{
	print(10);
	print(); // defalt���� �����Ǿ������� ����
	
	print2(100);



	return 0;
}