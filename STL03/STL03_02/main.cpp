#include <iostream>
#include <list>
#include <algorithm> // for copy()
using namespace std;

/* range & copy */

// �ݺ����� ���� (range) : [first, last)
// �󱸰�(empty)�� first == last�� ���

/* copy �˰���*/

// �ϳ��� ������ ������ �ٸ� �������� �����ϴ� �˰���
// 1��° ������ ������ ���� [first, last)�� ���޵�����, 
// 2��° ������ ���۸� ���޵ǹǷ� 1���� ������ ���� 2��° ������ ���� ������ �� ����

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