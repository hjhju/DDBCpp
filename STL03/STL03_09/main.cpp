#include <iostream>
#include <iterator>
#include <list>
#include <fstream>
using namespace std;

/* stream iterator */
// ��/��� ��Ʈ������ ��Ҹ� �аų� �������� �ݺ���
// include <iterator>
// 4���� ������ �ݺ��� ����
//  - ostream_iterator : ����ȭ�� ���
//  - ostreambuf_iterator : CharT ���
//  - istream_iterator : ����ȭ�� �Է�
//  - istreambuf_iterator : CharT �Է�

/* ostream_iterator */
//  - ��½�Ʈ��(ostream, ofstream, ostringstream)�� ����ؼ� ����� �ϴ� �ݺ���
//  - copy���� �˰��� �Լ��� ����ؼ� ��Ʈ���� ��� �ҋ� ���

int main()
{
	int n = 10;
	cout << n << endl;

	ostream_iterator<int> p(cout, ", ");
	//ostream_iterator<int> p(cout); // null�� ���Ƿ� �� �پ ��µ�

	*p = 20; // cout<<20<<", "
	*p = 30; // cout<<30<<", "

	list<int> s = { 1,2,3 };
	copy(begin(s), end(s), p);
	fill_n(p, 3, 0); // 0�� 3�� ���

	ofstream f("a.txt");
	ostream_iterator<int> p2(f, ", "); // ���Ͽ� ��µ�
	*p2 = 20;
	*p2 = 30;



	return 0;
}