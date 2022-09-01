#include <iostream>
#include <iomanip>
using namespace std;

/* Section18_02 ostream���� ����ϱ�  */

int main()
{
	// setf�� unsetf�� ��� �ɼ� �ٲٱ�
	/*
	cout.setf(std::ios::showpos); // +��ȣ ���
	cout << 108 << endl;
	cout << 200 << endl;

	cout.unsetf(std::ios::showpos); // +��ȣ ���ֱ�
	cout << 109 << endl;

	cout.unsetf(std::ios::dec); // 10���� ��� ����
	cout.setf(std::ios::hex); // 16���� ��� �ѱ�
	cout << 108 << endl;

	// �̷��Ե� ����
	cout.setf(std::ios::hex, std::ios::basefield);
	cout << 108 << endl;

	cout << std::dec;
	cout << 200 << endl;

	cout.setf(std::ios::uppercase);
	cout<<std::hex;
	cout << 200 << endl;
	*/

	// boolalpha�� �����ϸ� true�� 1�� �ƴ� true�� ��µ�
	cout << std::boolalpha;
	cout << true << " " << false;

	// ���е� �����ϱ�
	//cout << std::defaultfloat; // �⺻ ����
	//cout << std::scientific << std::uppercase; // ���������� ǥ��
	cout << std::showpoint;  // �Ҽ����� ����
	cout << std::setprecision(3) << 123.456 << endl;
	cout << std::setprecision(4) << 123.456 << endl;
	cout << std::setprecision(5) << 123.456 << endl;
	cout << std::setprecision(6) << 123.456 << endl;
	cout << std::setprecision(7) << 123.456 << endl;


	cout << -12345 << endl;
	cout.fill('*'); // ��ĭ�� '*'��ä����
	cout << std::setw(10) << -12345 << endl;
	cout << std::setw(10) << std::left << -12345 << endl;
	cout << std::setw(10) << std::right << -12345 << endl;
	cout << std::setw(10) << std::internal << -12345 << endl;



	return 0;
}