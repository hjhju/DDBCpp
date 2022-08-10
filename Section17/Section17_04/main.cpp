#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Section17_04 문자 접근하기와 배열로의 변환 */

int main()
{
	string my_str("abcdefg");
	cout << my_str[0] << endl;
	cout << my_str[3] << endl;
	my_str[3] = 'X';
	cout << my_str << endl;

	// 런타임 에러 발생
	try
	{
		// 예외처리를 넣으면 느려져서 아래는 런타임 에러 발생
		//my_str[100] = 'Z';

		my_str.at(100) = 'Z';
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	string my_str2("abcdefg");
	cout << my_str2.c_str() << endl;
	cout << my_str.c_str()[6] << endl;

	const char* arr = my_str2.c_str();  
	cout << (int)arr[6] << endl;
	cout << (int)arr[7] << endl; // c스타일 문자열인 것처럼 뒤에 널 문자를 넣어주므로 0이 나옴

	char buf[20];
	my_str2.copy(buf, 5, 0); // 복사는 되지만 널 문자는 자동으로 넣어주지않음 -> 쓰레기값 출력됨
	buf[5] = '\0';
	cout << buf << endl;



	return 0;
}