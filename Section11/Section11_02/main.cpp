#include "Student.h"
#include "Teacher.h"
using namespace std;

/* Section11_02 상속의 기본 (2) */

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
	//person.study() // 자식것을 부모가 쓸수는 없음


	return 0;
}