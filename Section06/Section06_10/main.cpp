#include <iostream>

using namespace std;

/* Section06_14 참조변수 reference variable */
/* Section06_15 참조와 const */
/* Section06_16 포인터와 참조의 멤버 선택 */

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

void doSomething2(const int& n) // 파라미터에 const를 붙이면 값을 바꿀수 없음
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

	ref = 10; // 값 변경 가능

	cout <<value<< " "<< ref << endl;
	cout << &value << " " << &ref << " "<<ptr<< " "<< &ptr << endl;

	const int y = 8;
	const int& ref2 = y; // const가 붙으면 ref 변수 초기화 가능

	doSomething(value); // 포인터 주소를 복사해서 넣어주는 것
	cout << value << " " << ref << endl; // 값이 변함

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