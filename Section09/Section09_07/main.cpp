#include <iostream>

using namespace std;

/* Section09_07 ��ȣ ������ �����ε��� �Լ���ü */

class Accumulator
{
private:
	int m_counter = 0;
public:
	int operator()(int i) { return (m_counter += i); }
};

int main()
{
	Accumulator acc;
	cout << acc(10) << endl; //functer��� �θ�
	cout << acc(20) << endl;


	return 0;
}