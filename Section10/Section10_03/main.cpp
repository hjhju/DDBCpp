#include <iostream>
#include <vector>
#include <string>
#include "Lecture.h"

using namespace std;

/* Section10_03 집합 관계 */


int main()
{
	// aggregation relationship
	
	//Student std1("Jack Jack", 0);
	//Student std2("Dash", 1);
	//Student std3("Violet", 2);

	// 동적 할당으로 선언
	Student *std1 = new Student("Jack Jack", 0);
	Student *std2 = new Student("Dash", 1);
	Student *std3 = new Student("Violet", 2);

	Teacher teacher1("prof. hong");
	Teacher teacher2("prof. good");

	Lecture lec1("Computer programming");
	lec1.assignTeacher(&teacher1);
	lec1.registerStudent(std1);
	lec1.registerStudent(std2);
	lec1.registerStudent(std3);

	Lecture lec2("Computational thinking");
	lec2.assignTeacher(&teacher2);
	lec2.registerStudent(std1);

	cout << lec1 << endl;
	cout << lec2 << endl;

	lec2.study();

	cout << lec1 << endl;
	cout << lec2 << endl;


	delete std1;
	delete std2;
	delete std3;

	return 0;
}