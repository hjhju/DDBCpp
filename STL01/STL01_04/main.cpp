#include <iostream>
#include <utility>

/* std::pair */
// ���� �ٸ� Ÿ���� ��ü 2���� �����ϴ� Ÿ��
// first, second ����� ���� ��ҿ� ����
// �Լ��� 2���� ���� �����ϰ� ������ pair�� ����

using namespace std;

template<typename T> void foo(T p)
{
	cout << p.first << ", " << p.second << endl;
}

/*
// �Լ� ���ø�
template<typename T1, typename T2>
pair<T1, T2> make_pair ( const T1& a, const T2& b)
{
 return pair<T1, T2>(a, b);
}
*/

int main()
{
	pair<int, double> p1(1, 3.4);

	cout << p1.first << endl;
	cout << p1.second << endl;

	foo(p1);

	// make_pair
	// pair�� ����� helper �Լ�
	// Ŭ���� ���ø��� ���ø� ���ڸ� ������ �� �����Ƿ� ����
	// ������, �Լ� ���ø��� ���ø� ���ڸ� ������ �� �����Ƿ� ����ϱ� ����

	foo(make_pair(1, 1));

	// c++17 ���ʹ� Ŭ���� ���ø��� ���ڸ� ���� �� �� �ִ�.
	foo(pair(2, 3.3));

	return 0;
}