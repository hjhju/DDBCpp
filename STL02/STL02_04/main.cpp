#include <iostream>
#include <vector>
#include <list>
using namespace std;

/* member type */

// STL에는 멤버 데이터, 멤버 함수 이외에도 '멤버 타입'이라는 개념 제공
// 템플릿 의존 타입 (template dependent type)의 경우 typename을 표기해야 함 
//    typename T::value_type
// 템플릿이 아닌 경우 typename을 표기하지 않음
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
	// typename : vlaue_type을 타입의 이름으로 해석

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