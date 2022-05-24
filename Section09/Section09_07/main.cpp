#include <iostream>

using namespace std;

/* Section09_07 괄호 연산자 오버로딩과 함수객체 */

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
	cout << acc(10) << endl; //functer라고 부름
	cout << acc(20) << endl;


	return 0;
}