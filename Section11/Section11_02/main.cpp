#include "Student.h"
#include "Teacher.h"
using namespace std;

/* Section11_02 ����� �⺻ (2) */

int main()
{
	Student std("jack jack");
	std.setName("jack2");
	std::cout<<std.getName()<<std::endl;

	Teacher teach("dr. hong");
	teach.setName("dr. kim");
	std::cout << teach.getName() << std::endl;

	std::cout << std << std::endl;
	std::cout << teach << std::endl;

	std.doNothing();
	teach.doNothing();

	std.study();
	teach.teach();

	Person person;
	person.setName("mr. kkk");
	std::cout << person.getName() << std::endl;
	//person.study() // �ڽİ��� �θ� ������ ����


	return 0;
}