#include <iostream>
#include <list>
#include <algorithm> // for copy()
using namespace std;

/* range & copy */

// 반복자의 구간 (range) : [first, last)
// 빈구간(empty)은 first == last인 경우

/* copy 알고리즘*/

// 하나의 구간의 내용을 다른 구간으로 복사하는 알고리즘
// 1번째 구간은 완전한 구간 [first, last)이 전달되지만, 
// 2번째 구간은 시작만 전달되므로 1번쨰 구간을 통해 2번째 구간의 끝을 예측할 수 있음

int main()
{
	list<int> s1 = { 1,2,3 };
	list<int> s2 = { 4, 5, 6 };

	auto p1 = begin(s1);
	auto p2 = end(s1);

	while (p1 != p2)
	{
		cout << *p1 << endl;
		++p1;
	}

	int x[5] = { 1,2,3,4,5 };
	int y[5] = { 0,0,0,0,0 };
	list<int> s3 = { 0,0,0,0,0 };

	copy(x, x + 5, y);
	copy(x, x + 5, begin(s3));

	for (auto& n : y)
	{
		cout << n << ", ";
	}
	cout << endl;

	return 0;
}