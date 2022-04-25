#include <iostream>
#include <string>
#include <string.h>

/* std::string */

// <string.h> or <cstring> -> c���ڿ� �Լ��� ���� ���
// strcpy(), strcmp() ���� ����� �ʿ� ���� �Ϲ� ������ ������ ������� �ڵ� ���

using namespace std;

//using namesapce std::string_literals; //string ���ø� ��� ����
//using namespace std::literals; // literal ���� ��� ��� ����

void foo(string s) { cout << "string" << endl; }
void foo(const char* s) { cout << "char*" << endl; }

int main()
{
	string s1 = "hello";
	string s2;
	char s[10];

	strcpy_s(s, s1.c_str()); // string�� const char*�� ����, ��ȯ�� ���ڿ��� �� ���ڷ� ������ ���ڿ�
	strcpy_s(s, s1.data()); // data()�� ����ص� �� (C++ 11 ���Ŀ��� null ���ڷ� ������ ���ڿ� ����)

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
	//user define literals : literal �ڿ� ���̻縦 �ٿ��� Ư�� Ÿ���� ��ü�� ����, c++11���� ó�� �Ұ���
	foo("hello"s); // string
	

	return 0; 
}