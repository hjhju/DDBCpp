#include <iostream>
#include <string>
#include <string.h>

/* std::string */

// <string.h> or <cstring> -> c문자열 함수를 위한 헤더
// strcpy(), strcmp() 등을 사용할 필요 없이 일반 변수와 유사한 방식으로 코드 사용

using namespace std;

//using namesapce std::string_literals; //string 관련만 사용 가능
//using namespace std::literals; // literal 관련 모두 사용 가능

void foo(string s) { cout << "string" << endl; }
void foo(const char* s) { cout << "char*" << endl; }

int main()
{
	string s1 = "hello";
	string s2;
	char s[10];

	strcpy_s(s, s1.c_str()); // string을 const char*로 변형, 반환된 문자열은 널 문자로 끝나는 문자열
	strcpy_s(s, s1.data()); // data()를 사용해도 됨 (C++ 11 이후에는 null 문자로 끝나는 문자열 리턴)

	cout << s << endl;
	

	s2 = s1; //strcpy(s2, s1)

	if (s1 == s2) //strcmp(s1, s2)
	{
		cout << "same" << endl;
	}

	string s3 = s1 + s2;
	cout << s3 << endl;

	string s4 = "3.4";
	double d = stod(s4);

	cout << d << endl;

	foo("hello"); // char*
	//user define literals : literal 뒤에 접미사를 붙여서 특정 타입의 객체를 만듦, c++11에서 처음 소개됨
	foo("hello"s); // string
	

	return 0; 
}