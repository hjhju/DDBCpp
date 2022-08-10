#include <iostream>
#include <string>

using namespace std;

/* Section17_05 string ����, ��ȯ, �����̱�, ����  */

int main()
{
	string str1("one");
	string str2;

	str2 = str1;
	cout << str2 << endl;

	//str2 = "two";
	// chaining ����
	str2.assign("two").append(" ").append("three");

	cout << str2 << endl;

	// swap ���
	swap(str1, str2);
	cout << str1 << " " << str2 << endl;

	str1.swap(str2);
	cout << str1 << " " << str2 << endl;

	// ���� ����
	str1 += "four";
	cout << str1 << endl;

	str1 = str2 + "five";
	cout << str1 << endl;

	str1.push_back('A');  // push back�� ���ڸ� ����
	cout << str1 << endl;

	// Ư�� �ڸ��� ���� ����
	string str3("aaaa");
	str3.insert(2, "bbb");
	cout << str3 << endl;

	return 0;
}