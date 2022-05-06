#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <forward_list>
using namespace std;

/* iterator category */

// list�� �ݺ��� : ++, -- ��� ����
// forward_list�� �ݺ��� : ++�� ����

// list�� �ݺ��� : ++������ ����������, +������ �������� ����
// vector�� �ݺ��� : ++, +���� ��� ������

int main()
{
	// vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };
	list<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	//sort(begin(v), end(v)); // list�� ��� ������ ��
	v.sort(); // ok !! ����Լ��δ� ��� ����

	for (auto& n : v)
		cout << n << " ";
	cout << endl;

	
	//list<int> s1 = { 1,2,3 };
	vector<int> s1 = { 1,2,3 };
	auto i = begin(s1);

	// �Է� : �ݺ��ڸ� ���ؼ� �����̳� ���� ��Ҹ� �о� ���� ��
	int n = *i; 

	// ��� : �ݺ��ڸ� ���ؼ� �����̳� ���� ��ҿ� ���� ���� ��
	*i = 20; 

	++i; //ok
	// i = i + 2; // vector�� �Ǵµ� list�� �ȵ�


	/* multipass guarantee ���� */
	// 2�� �̻��� �ݺ��ڰ� �����̳� ��ҿ� �����ϰ� �������� ����
	// list�� �ݺ��ڴ� multipass�� ���������� stream�� insert iterator�� multipass�� �������� ����
	auto i1 = begin(s1);
	auto i2 = i1;

	if (i1 == i2)
	{
		cout << (*i1 == *i2) << endl;
		cout << (++i1 == ++i2) << endl;
	}


	vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };

	// 1, 2������ �ּ� �䱸 ����? - �Է¹ݺ���
	auto p = find(begin(v1), end(v1), 5);
	// reverse�� �䱸����? - �����
	reverse(begin(v1), end(v1));
	// quick sort - ���� ���� �ݺ��� 
	sort(begin(v1), end(v1));

	for (auto& n : v1)
		cout << n << " ";
	cout << endl;

	// v1.sort(); // vector�� ��� ����Լ� sort�� ����, �Ϲ� �Լ� sort()�� ����ϸ� ��



	return 0;
}