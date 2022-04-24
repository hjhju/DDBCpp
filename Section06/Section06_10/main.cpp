#include <iostream>

using namespace std;

/* Section06_14 �������� reference variable */
/* Section06_15 ������ const */
/* Section06_16 �����Ϳ� ������ ��� ���� */

struct Something
{
	int v1;
	float v2;
};

struct Other
{
	Something st;
};

struct Person
{
	int age;
	double weight;
};


void doSomething(int &n)
{
	n = 20;
	cout << "in doSomething " << n << endl;
}

void doSomething2(const int& n) // �Ķ���Ϳ� const�� ���̸� ���� �ٲܼ� ����
{
	// n = 20;
	cout << "in doSomething2 " << n << endl;
}

int main()
{
	int value = 5;
	int* ptr = nullptr;
	ptr = &value;

	int& ref = value;
	cout << ref << endl;

	ref = 10; // �� ���� ����

	cout <<value<< " "<< ref << endl;
	cout << &value << " " << &ref << " "<<ptr<< " "<< &ptr << endl;

	const int y = 8;
	const int& ref2 = y; // const�� ������ ref ���� �ʱ�ȭ ����

	doSomething(value); // ������ �ּҸ� �����ؼ� �־��ִ� ��
	cout << value << " " << ref << endl; // ���� ����

	Other ot;
	int& v1 = ot.st.v1;


	int a = 1;
	doSomething2(a);
	doSomething2(a * 3);


	Person person;
	person.age = 5;
	person.weight = 60.1;

	cout << &person << " " << person.age << endl;

	Person& ref_p = person;
	ref_p.age = 16;
	cout << &person << " " << person.age << " "<<&ref_p<<endl;


	Person* ptr_p = &person;
	ptr_p->age = 30;
	(*ptr_p).age = 20;
	cout << &person << " " << person.age << " " << &ptr_p << endl;

	Person& ref_p2 = *ptr_p;
	ref_p2.age = 30;
	cout << &person << " " << person.age << " " << &ref_p2 << endl;


	return 0;
}