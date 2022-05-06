#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <forward_list>
using namespace std;

/* iterator category */

// list의 반복자 : ++, -- 모두 가능
// forward_list의 반복자 : ++만 가능

// list의 반복자 : ++연산은 제공되지만, +연산은 제공되지 않음
// vector의 반복자 : ++, +연산 모두 제공됨

int main()
{
	// vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };
	list<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	//sort(begin(v), end(v)); // list의 경우 오류가 뜸
	v.sort(); // ok !! 멤버함수로는 사용 가능

	for (auto& n : v)
		cout << n << " ";
	cout << endl;

	
	//list<int> s1 = { 1,2,3 };
	vector<int> s1 = { 1,2,3 };
	auto i = begin(s1);

	// 입력 : 반복자를 통해서 컨테이너 안의 요소를 읽어 오는 것
	int n = *i; 

	// 출력 : 반복자를 통해서 컨테이너 안의 요소에 값을 쓰는 것
	*i = 20; 

	++i; //ok
	// i = i + 2; // vector는 되는데 list는 안됨


	/* multipass guarantee 개념 */
	// 2개 이상의 반복자가 컨테이너 요소에 동일하게 접근함을 보장
	// list의 반복자는 multipass를 보장하지만 stream과 insert iterator는 multipass를 지원하지 못함
	auto i1 = begin(s1);
	auto i2 = i1;

	if (i1 == i2)
	{
		cout << (*i1 == *i2) << endl;
		cout << (++i1 == ++i2) << endl;
	}


	vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };

	// 1, 2인자의 최소 요구 조건? - 입력반복자
	auto p = find(begin(v1), end(v1), 5);
	// reverse의 요구조건? - 양방향
	reverse(begin(v1), end(v1));
	// quick sort - 임의 접근 반복자 
	sort(begin(v1), end(v1));

	for (auto& n : v1)
		cout << n << " ";
	cout << endl;

	// v1.sort(); // vector의 경우 멤버함수 sort가 없음, 일반 함수 sort()를 사용하면 됨



	return 0;
}