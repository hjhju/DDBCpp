#include <iostream>
#include <string>
#include <iomanip> // input/output manipulators
using namespace std;

/* Section18_01 istream���� �Է¹ޱ�  */

int main()
{
	// 1) console in/out ����
	//cout << "enter a number" << endl;

	//int i;
	//float f;
	//cin >> i >> f;
	//cout << i << " " << f << endl;

	// 2) ���۷� ������ ���ڼ� �ޱ�
	/*
	char buf[5];

	// ������ ���ڸ�ŭ ���ڸ� buf�� �Է¹��� (���������� �Է� ����)
	cin >> setw(5) >> buf;
	cout << buf << endl;

	cin >> setw(5) >> buf;
	cout << buf << endl;

	cin >> setw(5) >> buf;
	cout << buf << endl;
	*/


	// 3) �ѱ��ھ� �Է¹ޱ�
	/*
	char ch;
	// ��ĭ���� �Է¹���
	//while (cin >> ch)
	//	cout << ch;

	// ��ĭ ����Ͽ� �Է� ����
	//while (cin.get(ch))
	//	cout << ch;

	char buf[5];
	cin.get(buf, 5);
	cout <<cin.gcount() << " " << buf << endl;  // gcount()�� ����� �о�鿴���� üũ

	cin.getline(buf, 5);
	cout << cin.gcount() << " " << buf << endl; 
	*/

	// 4) string�� ���, ����� ������� ����
/*	string buf2;
	getline(cin, buf2);
	cout << cin.gcount() << " " << buf2 << endl; */ 

	// 5) ignore�� �Է¹��� ���� ����

	//char buf3[1024];
	//cin.ignore();  // �Է¹����� �ѱ��ڸ� ������
	//cin.ignore(2);  // �Է¹����� �α��ڸ� ������
	//cin >> buf3;
	//cout << buf3 << endl;

	// 6) peek()�� ���ۿ��� �������� �ʰ� ��¦ ���� �뵵

	//char buf3[1024];
	//cout << (char)cin.peek() << endl;
	//cin >> buf3;
	//cout << buf3 << endl;


	// 7) unget() & putback() 

	char buf3[1024];
	cin >> buf3;
	cout << buf3 << endl;

	cin.unget();  // �������� ���� ���� ���ۿ� ����
	cin >> buf3;
	cout << buf3 << endl;

	cin.putback('A'); // ���ϴ� ���ڸ� ���ۿ� �ٽ� ����
	cin >> buf3;
	cout << buf3 << endl;

	return 0;
}