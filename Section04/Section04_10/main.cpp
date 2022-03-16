#include <iostream>
#include <string>

using namespace std;

/* Section04_10 : ����ü struct */

struct Person
{
	double height; // ������ ����ü ������ ��
	float weight;
	int	age;
	string name;

	void print()
	{
		cout << height << " " << weight << " " << age << " " << name;
		cout << endl;
	}
};

void pringPerson(Person ps)
{
	// .�� ����� �����ϱ����� operator
	cout << ps.height << " " << ps.weight << " " << ps.age << " " << ps.name;
	cout << endl;
}

struct Family
{
	Person me, mom, dad;
};

Person getMe()
{
	Person me{ 2.0, 100.0, 20, "Jack" };

	return me;
}

struct Employee // 2 + (2) + 4 + 8 = 16 // (2)�� padding�̶�� �θ�
{
	short id; // 2 bytes
	int age; // 4 bytes
	double wage; // 8 bytes
};
int main()
{
	Person me{ 2.0, 100.0, 20, "Jack" };
	/*
	// ���� ���
	me.age = 20;
	me.name = "Jack";
	me.height = 2.0;
	me.weight = 100.0;
	*/
	pringPerson(me);

	me.print();

	Person me2;
	me2 = me;
	me2.print();

	Person me_from_func = getMe();
	me_from_func.print();

	cout << sizeof(Employee) << endl;

	return 0;
}