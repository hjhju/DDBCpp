#include <iostream>

using namespace std;

/* Section07_04 �ּҿ� ���� �μ� ���� (call by adress)  */

// C ��Ÿ�� �ڵ� !
void foo2(int* arr, int length)
{
	for (int i = 0; i < length; i++)
		cout << arr[i] << endl;
	arr[0] = 10;
}

// �ּҰ� ����
void foo(int* ptr)
{
	cout << *ptr << " " << ptr<< " " <<& ptr << endl;
	*ptr = 10; // const ������ �ȵ�
}

void getSinCos(const double degrees, double *sin_out, double *cos_out)
{
	static const double pi = 3.141592 / 180.0;
	const double radians = degrees * pi;
	*sin_out = std::sin(radians);
	*cos_out = std::cos(radians);
}

int main()
{
	int value = 5;
	cout << value << " " << &value << endl;

	int* ptr = &value;
	cout << &ptr << endl;

	foo(ptr);
	foo(&value);
	//foo(5);
	cout << endl;

	double sin(0.0);
	double cos(0.0);

	// sin�� cos �� �ּҸ� �Ѱܼ� getSinCos �Լ��� �Ű������� ������ sin_out, cos_out �� ���� sin�� cos �� �ּҸ� ����Ű�� ��
	// �̸� ���Ͽ� ���� ������ ���� �ٲ����� �ּ��� ���ΰ��� sin�� cos �� ���� �ٲ�� ��
	// *�� ������ ������ ������ ���������� �� (������ �������� �ּҰ����� ã�ư��� �ִ� �����Ͱ�)
	getSinCos(30.0, &sin, &cos);
	cout << sin << " " << cos << endl;
	cout << endl;

	int arr[4]{ 1,2,3,4 };
	foo2(arr, 4);
	for (int i = 0; i < 4; i++)
		cout << arr[i] << endl;



	return 0;
}