#include <iostream>
#include <list>
#include <vector>
#include <iterator>
using namespace std;

/* tag dispatching */

/* advance 함수 
  - <iterator> 헤더
  - 반복자 N만큼 전진(후진)하는 함수
반복자를 이동할 때
  - + : 임의 접근 반복자만 가능
  - ++ : 모든 반복자가 가능하지만, 임의 접근 반복자의 경우 +로 이동하는 것이 빠름
  - 임의 접근 반복자인 경우와 그렇지 않은 경우를 다르게 구현해야됨 - tag dispatching 기술을 사용
*/

/* iterator category tag */
// <iterator> 헤더
// 반복자의 5가지 category를 나타내는 타입, empty class로 제공
// c++17에서 추가된 contiguous iterator는 별도의 tag가 제공되지 않음

/*
// 5가지 category 타입

struct input_iterator_tag {}; // empty class
struct output_iterator_tag {};
struct forward_iterator_tag
	: public input_iterator_tag {};
struct bidirectional_iterator_tag
	: public forward_iterator_tag{};
struct random_access_iterator_tag
	: public bidirectional_iterator_tag {};


// 반복자를 만들때... 자신의 category를 알려준다.

template<typename T> class vector_iterator
{
public:
	using iterator_category = random_access_iterator_tag;
};

template<typename T> class list_iterator
{
public:
	using iterator_category = bidirectional_iterator_tag;
};

*/

/* tag dispatching 기술 정리 - "c++ template programming 과정" 참고 */

// 1. 함수 인자를 사용한 오버로딩
/*
template<typename T>
void eadvance_imp(T& p, int n, random_access_iterator_tag)
{
	cout << "random"<< endl;
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
	eadvance_imp(p, n, typename T::iterator_category());
}
*/

// 2. C++17 if constexpr 사용
/*
#include <type_traits>
template<typename T>
void eadvance(T& p, int n)
{
	if constexpr (is_same<T::iterator_category, random_access_iterator_tag>::value)
	{
		p = p + n;
	}
	else
	{
		while (n--)
			++p;
	}
}
*/

// 3. enable if를 사용 - SFINAE 개념 사용.
template<typename T>
typename enable_if<is_same<typename T::iterator_category, random_access_iterator_tag>::value>::type
eadvance(T& p, int n)
{
	p = p + n;
}

template<typename T>
typename enable_if<is_same<typename T::iterator_category, input_iterator_tag>::value>::type
eadvance(T& p, int n)
{
	while (n--)
		++p;
}

int main()
{
	//list<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = begin(s);

	// 반복자 p를 5칸 전진하고 싶다.
	
	// p = p + 5;
	//advance(p, 5);
	eadvance(p, 5); // vector면 random, list면 input

	cout << *p << endl;
	
	

	return 0;
}