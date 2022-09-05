#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/* Section18_03 문자열 스트림(흐름)  */

int main()
{
	stringstream os;

	// << : insertion operator, >> : extraction operator
	os << "hello, world!1";  
	os << "hello, world!2";  // 연결되어 쭉 나옴
	
	os.str("hello, world!"); // hello, world!로 대체됨

	string str;

	// os >> str; // 공백 기준으로 자름

	str = os.str();  // 전체를 다 가져옴
	cout << str << endl;


	int i = 12345;
	double d = 67.89;

	os << i << " " << d;
	// 숫자로 넣은것을 문자열로 받기
	//string s1;
	//string s2;
	//os >> s1 >> s2;
	//cout << s1 << "|" << s2 << endl;

	// 숫자로 넣은 것을 숫자로 받기
	os << "12345 67.89";
	int i2;
	double d2;
	os >> i2 >> d2;
	cout << i2 << "|" << d2 << endl;

	//os.str(""); // 모두 빈칸으로 바꾸기
	os.clear(); // 
	os << "hello";
	cout << os.str() << endl;




	return 0;
}