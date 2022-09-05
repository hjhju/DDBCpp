#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/* Section18_03 ���ڿ� ��Ʈ��(�帧)  */

int main()
{
	stringstream os;

	// << : insertion operator, >> : extraction operator
	os << "hello, world!1";  
	os << "hello, world!2";  // ����Ǿ� �� ����
	
	os.str("hello, world!"); // hello, world!�� ��ü��

	string str;

	// os >> str; // ���� �������� �ڸ�

	str = os.str();  // ��ü�� �� ������
	cout << str << endl;


	int i = 12345;
	double d = 67.89;

	os << i << " " << d;
	// ���ڷ� �������� ���ڿ��� �ޱ�
	//string s1;
	//string s2;
	//os >> s1 >> s2;
	//cout << s1 << "|" << s2 << endl;

	// ���ڷ� ���� ���� ���ڷ� �ޱ�
	os << "12345 67.89";
	int i2;
	double d2;
	os >> i2 >> d2;
	cout << i2 << "|" << d2 << endl;

	//os.str(""); // ��� ��ĭ���� �ٲٱ�
	os.clear(); // 
	os << "hello";
	cout << os.str() << endl;




	return 0;
}