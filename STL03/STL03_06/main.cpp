#include <iostream>
#include <list>
#include <vector>
#include <iterator>
using namespace std;

/* iterator_traits */

//  - <iterator> 헤더
//  - raw pointer에는 "member type이 없다는 문제를 해결하기위한 도구
//  - 반복자의 value type이 필요할때, iterator_traits를 통해 value_type을 사용

// value_type을 사용하는 2가지 방식
//  - T::value_type : T가 Raw pointer라면 error
//  - iterator_traits<T>::value_type : T가 Raw pointer라도 문제 없음


/*
template<typename T> struct iterator_traits
{
	using value_type = typename T::value_type;
};

// 핵심 : 포인터 버전을 부분 특수화
template<typename T> struct iterator_traits<T*>
{
	using value_type = T;
};
*/

template<typename T>
typename iterator_traits<T>::value_type sum(T first, T last)
{
	// 구간의 합을 보관할 변수
	// T:반복자 타입
	// T::value_type : 반복자가 가리키는 타입
	// typename T::value_type s = 0;

	//typename iterator_traits<T>::value_type s = 0;

	// value_type 대신에 auto/decltype을 사용할 경우
	// type deduction규칙을 정확히 알고 사용해야 한다!!
	
	// decltype(*first) s = 0; // decltype(*포인터타입) error!
	typename remove_reference<decltype(*first)>::type s = 0;
	
	while (first != last)
	{
		s = s + *first;
		++first;
	}
	return s;
}


template<typename T>
void foo(T a)
{
	// T가 반복자 일때 반복자가 가리키는 타입을 사용하고 싶다.
	typename T::value_type n1;
	typename iterator_traits<T>::value_type n2;

}

template<typename T>
void eadvance_imp(T& p, int n, random_access_iterator_tag)
{
	cout << "random" << endl;
	p = p + n;
}
template<typename T>
void eadvance_imp(T& p, int n, input_iterator_tag)
{
	cout << "input" << endl;
	while (n--)
		++p;
}
template<typename T>
void eadvance(T& p, int n)
{
	// 반복자의 종류에 따라서 다른 함수를 선택
	eadvance_imp(p, n, typename iterator_traits<T>::iterator_category());
}

int main()
{
	//list<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	//vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	int s[10] = { 1,2,3,4,5,6,7,8,9,10 };

	// raw pointer에는 member type이 없으므로 알고리즘 함수를 만들때 문제가 생김
	int n = sum(begin(s), end(s)); 
	cout << n << endl;

	auto p = begin(s);
	eadvance(p, 5);
	cout << *p << endl;

	return 0;
}