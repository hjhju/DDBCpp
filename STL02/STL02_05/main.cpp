#include <iostream>
#include <list>
using namespace std;

/* c++17�� STL */

// c++17���ʹ� Ŭ���� ���ø��� ���ø� ���ڸ� ��������� �������� �ʾƵ� �����Ϸ��� �߷� ����
// List Ŭ������ T�κ��� ���� �߷� 

template<typename T> class List
{
public:
	List(int sz, T initValue) {};
};

int main()
{
	List<int> s1(10, 0);
	List      s2(10, 0); //c++17 ���� ����

	list<int> s3 = { 1,2,3 };
	list	  s4 = { 1 ,2, 3 }; //c++17 ���� ����

	return 0;
}