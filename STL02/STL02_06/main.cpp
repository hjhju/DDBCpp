#include <iostream>
#include <algorithm>
using namespace std;

/* Concept - c++20 */
// STL�� ������ �����ϴ� Ÿ�Կ� ���ؼ� ������!!

struct Point
{
	int x, y;
};

int main()
{
	int n1 = min(1, 2);
	int n2 = min({ 1, 2, 3, 4 ,5 });

	cout << n2 << endl;

	Point p1, p2;

	//min(p1, p2); // <, > ������ �����ؾ��Ѵ�. LessThanComparable�� �����ؾߵ�

	return 0;
}