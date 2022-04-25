#include <iostream>
#include <vector>
#include <list>
using namespace std;

/* member type */

// STL���� ��� ������, ��� �Լ� �̿ܿ��� '��� Ÿ��'�̶�� ���� ����
// ���ø� ���� Ÿ�� (template dependent type)�� ��� typename�� ǥ���ؾ� �� 
//    typename T::value_type
// ���ø��� �ƴ� ��� typename�� ǥ������ ����
//    list<int>::value_type


/*
template <typename T>
void print(vector<T>& c)
{
	int n = c.front();
	cout << n << endl;
}
*/


template <typename T>
void print(T& c)
{
	// T : list<double>
	// T::value_type => list<double>::value_type ==> double
	// typename : vlaue_type�� Ÿ���� �̸����� �ؼ�

	//int n = c.front();
	typename T::value_type n = c.front();
	cout << n << endl;
}

template <typename T>
void sum(T first, T last)
{
	typename T::value_type sum = 0;
	while (first != last)
	{
		sum += *first;
		first++;
	}
	cout << sum << endl;
}

int main()
{
	//vector<double> v = { 1,2,3 };
	list<double> v = { 1,2,3 };

	print(v);

	sum(v.begin(), v.end());

	list<int>::size_type n = v.size();

	return 0;
}