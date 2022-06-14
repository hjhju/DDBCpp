#include <iostream>

using namespace std;

/* Section11_03 유도된 클래스들의 생성 순서 */

class Mother
{
public:
	int m_i;

	Mother(const int &m_in=0) :m_i(m_in)
	{
		cout << "Mother" << endl;
	}
};

class Child :public Mother
{
public:
	double m_d;

public:
	Child() :m_d(1.0), Mother(1024) //: m_i(1024) Mother의 변수는 inialized list 형태로는 초기화 안됨 
	{
		cout << "Child" << endl;
	}
};

int main()
{
	Mother m1;
	cout << endl;
	Child c1; //mother부터 생성됨
	
	return 0;
}