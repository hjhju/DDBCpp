#include <iostream>
#include <string>

using namespace std;

/* Section04_06 : 문자열 std string 소개 */

int main()
{
	const char my_strs [] = "Hello, World";

	const string my_hello = "Hello, World"; // string은 사용자 정의 자료형

	cout << my_hello << endl;


	cout << "Your age? : ";
	string age;
	//cin >> age;
	std::getline(std::cin, age);
	
	// \n을 만날때 까지 최대 32767개의 글자를 무시하라는 의미
	// 32767은 매직 넘버
	// std::cin.ignore(32767, '\n');
	// 32767대신 아래와같이 표현 가능
	// streamsize는 버퍼 크기
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout << "Your name? : ";
	string name;
	//cin >> name; // 빈칸을 넣어서 입력하면 다음 변수에 들어가버림
	std::getline(std::cin, name); // 엔터 칠때까지 입력 받음

	cout << name << " " << age << endl;


	// 문자열 더하기 가능
	string a("Hello, ");
	string b("World");
	string hw = a + b;

	hw += "i'm good";

	cout << hw << endl;

	cout << a.length() << endl;


	return 0;
}