#include <iostream>
#include <string>

using namespace std;

/* Section17_05 string 대입, 교환, 덧붙이기, 삽입  */

int main()
{
	string str1("one");
	string str2;

	str2 = str1;
	cout << str2 << endl;

	//str2 = "two";
	// chaining 구조
	str2.assign("two").append(" ").append("three");

	cout << str2 << endl;

	// swap 기능
	swap(str1, str2);
	cout << str1 << " " << str2 << endl;

	str1.swap(str2);
	cout << str1 << " " << str2 << endl;

	// 연산 가능
	str1 += "four";
	cout << str1 << endl;

	str1 = str2 + "five";
	cout << str1 << endl;

	str1.push_back('A');  // push back은 문자만 가능
	cout << str1 << endl;

	// 특정 자리에 삽입 가능
	string str3("aaaa");
	str3.insert(2, "bbb");
	cout << str3 << endl;

	return 0;
}