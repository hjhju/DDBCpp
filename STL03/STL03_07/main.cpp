#include <iostream>
#include <list>
#include <iterator>

using namespace std;

/* insert iterator */

// �����̳� ��Ҹ� �߰��ϴ� ���
//  - ��� �Լ� (push_xxx,/ emplace_Xxx/ insert) ���
//  - ���� �ݺ��� (insert iterator)

// ���� �ݺ���
//  - <iterator> ���
//  - �����̳ʿ� ��Ҹ� ������ �� ����ϴ� �ݺ���
//  - 3���� ���� (����, �Ĺ�, ���� ����) ����

// �⺻ ���
//   - back_insert_iterator<�����̳� Ŭ���� �̸�> p(�����̳� ��ü)

/* 
// c++ ǥ�ؿ� ������ 
template<typename T>
back_insert_iterator<T>
back_inserter(T& c)
{
	return back_insert_iterator<T>(c);
}
*/


int main(int argc, char **argv)
{
	list<int> s = { 1,2,3,4,5 };
	s.push_back(10);

	back_insert_iterator<list<int>> p(s); // ���� �ݺ���

	*p = 20; // s.push_back(20)�� ����


	int x[5] = { 10,20,30,40,50 };

	// for (int i = 0; i < 5; i++)
	//		s.push_back(x[i]);


	// ���Թݺ��ڸ� ���� ���� ���� �ݺ����� ���� �ʰ� �ѹ��� ���� ����
	copy(x, x + 5, p); 

	//copy(x, x + 5, s.begin()); // ����� ��

	// ���� �ڵ������� �̷��� ���
	copy(x, x + 5, back_inserter(s)); 

	// ���� ������ ��� x�� ������ �������� ���Ե�
	//copy(x, x + 5, front_inserter(s));

	// ���� ������ ��� ������ ���ڰ� 2�� �ʿ� - �����̳ʿ� ������ ��ġ�� ��Ÿ���� �ݺ���
	// ���� ���԰� �ٸ��� ������ �������� ����
	copy(x, x + 5, inserter(s, s.begin())); 


	for (auto& n : s)
	{
		cout << n << endl;
	}

	return 0;
}