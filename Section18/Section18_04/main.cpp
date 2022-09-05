#include <iostream>
#include <cctype>
#include <string>
#include <bitset>
using namespace std;

/* Section18_04 흐름상태 (stream state) 와 입력 유효성 검증 (input validation)  */


// www.cplusplus.com/reference/cctype

// 내가 원하는 문자인지를 검증
void printCharacterClassification(const int &i)
{
	cout << boolalpha;
	cout << "isalnum " << bool(std::isalnum(i)) << endl;
	cout << "isblank " << bool(std::isblank(i)) << endl;
	cout << "isdigit " << bool(std::isdigit(i)) << endl;
	cout << "islower " << bool(std::islower(i)) << endl;
	cout << "isupper " << bool(std::isupper(i)) << endl;

}

// www.cplusplus.com/reference/ios
void printState(const std::ios& stream)
{
	cout << boolalpha;
	cout << "good()=" << stream.good() << endl;
	cout << "eof()=" << stream.eof() << endl;
	cout << "fail()=" << stream.fail() << endl;
	cout << "bad()=" << stream.bad() << endl;
}

// 모두 숫자인지 한글자씩 비교하는 방식
bool isAllDigit(const string & str)
{
	bool ok_flag = true;
	for (auto e : str)
	{
		if (!std::isdigit(e))
		{
			ok_flag = false;
			break;
		}
	}
	return ok_flag;
}

int main()
{
	//while (true)
	//{
	//	int i;
	//	cin >> i;

	//	printState(cin);

	//	// 다음과 같은 방법도 가능은 함 (하지만 printState같은 방식을 선호)
	//	//cout << boolalpha;
	//	//cout << std::bitset<8>(cin.rdstate()) << endl;
	//	//cout << std::bitset<8>(std::istream::goodbit) << endl;
	//	//cout << std::bitset<8>(std::istream::failbit) << endl;
	//	//cout << !bool((cin.rdstate() & std::istream::failbit) !=0) << endl;

	//	printCharacterClassification(i);

	//	cin.clear();
	//	cin.ignore(1024, '\n');
	//	cout << endl;

	//}

	cout << boolalpha;
	cout << isAllDigit("1234") << endl;
	cout << isAllDigit("a1234") << endl;


	return 0;
}