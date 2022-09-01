#include <iostream>
#include <string>
#include <iomanip> // input/output manipulators
using namespace std;

/* Section18_01 istream으로 입력받기  */

int main()
{
	// 1) console in/out 사용법
	//cout << "enter a number" << endl;

	//int i;
	//float f;
	//cin >> i >> f;
	//cout << i << " " << f << endl;

	// 2) 버퍼로 정해진 글자수 받기
	/*
	char buf[5];

	// 지정된 숫자만큼 글자를 buf에 입력받음 (순차적으로 입력 받음)
	cin >> setw(5) >> buf;
	cout << buf << endl;

	cin >> setw(5) >> buf;
	cout << buf << endl;

	cin >> setw(5) >> buf;
	cout << buf << endl;
	*/


	// 3) 한글자씩 입력받기
	/*
	char ch;
	// 빈칸없이 입력받음
	//while (cin >> ch)
	//	cout << ch;

	// 빈칸 고려하여 입력 받음
	//while (cin.get(ch))
	//	cout << ch;

	char buf[5];
	cin.get(buf, 5);
	cout <<cin.gcount() << " " << buf << endl;  // gcount()는 몇글자 읽어들였는지 체크

	cin.getline(buf, 5);
	cout << cin.gcount() << " " << buf << endl; 
	*/

	// 4) string의 경우, 사이즈가 고려되지 않음
/*	string buf2;
	getline(cin, buf2);
	cout << cin.gcount() << " " << buf2 << endl; */ 

	// 5) ignore로 입력받은 문자 무시

	//char buf3[1024];
	//cin.ignore();  // 입력받을때 한글자를 무시함
	//cin.ignore(2);  // 입력받을때 두글자를 무시함
	//cin >> buf3;
	//cout << buf3 << endl;

	// 6) peek()은 버퍼에서 꺼내지는 않고 살짝 보는 용도

	//char buf3[1024];
	//cout << (char)cin.peek() << endl;
	//cin >> buf3;
	//cout << buf3 << endl;


	// 7) unget() & putback() 

	char buf3[1024];
	cin >> buf3;
	cout << buf3 << endl;

	cin.unget();  // 마지막에 읽을 것을 버퍼에 넣음
	cin >> buf3;
	cout << buf3 << endl;

	cin.putback('A'); // 원하는 글자를 버퍼에 다시 넣음
	cin >> buf3;
	cout << buf3 << endl;

	return 0;
}