#include <iostream>
#include <cstring> // for strch()

using namespace std;

/* make find algorithm */

// �κ� ���ڿ������� �˻�
// �����ּҿ� ������ ����� �ּ� ����
// �˻� ��� : [first, last)
// ��� �迭�� ���� ���� �˻��� ���� �Ҽ� �ֵ��� �ϱ����� �Լ� ���ø� ���!!

// template<typename T>
// T* efind(T* first, T* last, T* vlaue)
template<typename T1, typename T2>
T1 efind(T1 first, T1 last, T2 vlaue)
{
	while (first != last && *first != vlaue)
	{
		++first;
	}
	return first;
}

int main()
{
	char s[] = "abcdefg";

	// c����� strch() �Լ�
	// ���ڿ����� ���ڸ� �˻�, ���ڿ��� ���� �ּҸ� �޾Ƽ� �ι���('\0')�� ������ ���� �˻�
	// ���� ���� ������ �ι��ڵ� �˻� ��� ����, ���н� null ������ ��ȯ
	char* p = strchr(s, 'c');

	if (p == 0)
		cout << "fail" << endl;
	else
		cout << "success : " << *p << endl;


	char* p2 = efind(s, s + 4, 'f');
	if (p2 == 0)
		cout << "fail" << endl;
	else
		cout << "success : " << *p2 << endl;

	double x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	// ù��° �ι����� double������ �������̹Ƿ� �������� double�� �־���ߵ� 7�̶�� ���� ������
	// template<typename T1, typename T2> �� �ؼ� ������ Ÿ�԰� �˻��� ����� Ÿ���� �ٸ� Ÿ���� ����ϸ� ��!!
	// ������ ���۰� �������� ���� ������ ������(*)ǥ�⸦ ���� ����!!
	// ����� efind ����!
	double* p3 = efind(x, x + 5, 11);  
	if (p3 == x+5)
		cout << "fail" << endl;



	return 0;
}