#include <iostream>
#include <algorithm>
using namespace std;

/* Concept - c++20 */
// STL은 조건을 만족하는 타입에 대해서 동작함!!

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

	//min(p1, p2); // <, > 연산을 지원해야한다. LessThanComparable을 만족해야됨

	return 0;
}