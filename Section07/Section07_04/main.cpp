#include <iostream>

using namespace std;

/* Section07_06 �ζ��� �Լ� */

// ������Ͽ� �Լ� ���ǽ� �ַ� ���
// inline���� ó���ϸ� �Լ��� �ƴ� �� ó�� �۵�
// inline�� ���� �������ٰ� �˷���, �ֱٿ��� ���ٰ� ������ �������ٴ� ������ ����

inline int min(int x, int y)
{
	return x > y ? y : x;
}

int main()
{
	cout << min(5, 6) << endl;
	// cout<<(5 > 6 ? 6 : 5;)<<endl; ó�� �۵�
	cout << min(3, 2) << endl;

	return 0;
}