#include <iostream>

using namespace std;

/* Section07_07 �Լ� �����ε�  */

// �Լ� �����ε�
//   - ������ �̸��� ���� �Լ��� ������ ����� ��
//   - ����Ÿ���� �޶�, �Ķ���Ͱ� ������ �ȵ�!!

int add(int x, int y)
{
	return x + y;
}

double add(double x, double y)
{
	return x + y;
}

void getRandom(int &x){}
void getRandom(double& x) {}

// �Ʒ��� ���� ���� Ÿ������ �νĵ�!!
//typedef int my_int;
//void print(int x) {}
//void print(my_int x) {}

void print(char* value) {}
void print(unsigned int value) {}
void print(float value) {}


int main() 
{
	cout << add(1, 2) << endl;
	cout << add(3.0, 4.0) << endl;

	print(0u);
	print((unsigned int)'a');
	print(3.14f);

	return 0;
}