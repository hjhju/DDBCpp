#include <iostream>
#include <iterator>
#include <list>
#include <fstream>
using namespace std;

/* stream iterator */
// 입/출력 스트림에서 요소를 읽거나 쓰기위한 반복자
// include <iterator>
// 4가지 종류의 반복자 제공
//  - ostream_iterator : 서식화된 출력
//  - ostreambuf_iterator : CharT 출력
//  - istream_iterator : 서식화된 입력
//  - istreambuf_iterator : CharT 입력

/* ostream_iterator */
//  - 출력스트림(ostream, ofstream, ostringstream)을 사용해서 출력을 하는 반복자
//  - copy등의 알고리즘 함수를 사용해서 스트림에 출력 할떄 사용

int main()
{
	int n = 10;
	cout << n << endl;

	ostream_iterator<int> p(cout, ", ");
	//ostream_iterator<int> p(cout); // null이 들어가므로 다 붙어서 출력됨

	*p = 20; // cout<<20<<", "
	*p = 30; // cout<<30<<", "

	list<int> s = { 1,2,3 };
	copy(begin(s), end(s), p);
	fill_n(p, 3, 0); // 0을 3번 출력

	ofstream f("a.txt");
	ostream_iterator<int> p2(f, ", "); // 파일에 출력됨
	*p2 = 20;
	*p2 = 30;



	return 0;
}