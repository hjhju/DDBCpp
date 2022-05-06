#include <iostream>
#include <vector>
using namespace std;

/* Section07_01 �Ű������� �������� ���� */
/* Section07_02 ���� ���� ���� (call by value) */
/* Section07_03 ������ ���� ���� (call by reference) */


//void printArr(int (&arr)[4]) // element�� ������ �ݵ�� ���ߵ�
void printArr(const vector<int>& arr) // �̰� �ξ� ����
{
	cout << arr.size() << " "<<&arr<<endl;
}

// ���� ���� �����ε� foo2(3)�̸� ������ ������ �߻� -> 3�� ���̰� �ּҸ� �������� �ʱ⶧�� -> &�� ���ų� const ���̸� �ذ��
// �Ⱥ��ϴ� ���̸� const�� �� ���̴°��� ����
void foo2(const int& x) 
{
	cout << x << endl;
}

// ((int*) &ptr)�̶�� �����ϸ� ��
void foo3(int *&ptr)
{
	cout << ptr << " " << &ptr << endl;
	ptr++;
}

void getSinCos(const double &degrees, double& sin_out, double& cos_out)
{
	static const double pi = 3.141592 / 180.0;
	const double radians = degrees * pi ;
	sin_out = std::sin(radians);
	cos_out = std::cos(radians);
}

void addOne(int &y)
{
	cout << "In func " << y << " " << &y << endl;
	y = y + 1;
}


void doSomething(int y)
{
	cout << "In func " << y << " " << &y << endl;
}


int foo(int x, int y)
{
	return x + y;
} // x and y are destroyed here

int main()
{
	int x = 1, y = 2;

	foo(6, 7); // 6, 7 : arguments (actual parameters, ������
	foo(x, y + 1); 

	// ���� ���޵�, �Լ��� main������ �ּҰ��� �ٸ�
	doSomething(5);
	doSomething(x);
	cout << "In main " << x << " " << &x << endl;
	doSomething(x+1);
	cout<< endl;

	// �Լ��� ���ο����� �ּҰ��� ����, ���� �������
	x = 5;
	cout << "In main " << x << " " << &x << endl;
	addOne(x);
	cout << "In main " << x << " " << &x << endl;
	cout << endl;

	double sin(0.0);
	double cos(0.0);

	getSinCos(30.0, sin, cos);
	cout << sin << " " << cos << endl;
	cout << endl;

	foo2(6);

	int* ptr = &x;
	cout << ptr << " " << &ptr << endl;
	foo3(ptr);
	cout << ptr << " " << &ptr << endl;
	cout << endl;

	int arr[]{ 1,2,3,4 };
	vector<int> arr2{ 1,2,3,4 };
	cout << arr2.size() << " " << &arr2 << endl;
	printArr(arr2);

	return 0;
}