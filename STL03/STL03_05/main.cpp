#include <iostream>
#include <iterator>
using namespace std;

/* 반복자와 member type */

// STL02_02에서 만든 slist_iterator 변형
// 반복자를 만들 때 반드시 member type을 제공해야한다.

// iterator class
// - <iterator> 헤더
// - 모든 반복자의 기반 클래스 - c++17이전까지, c++17부터는 사용되지 않음

template<typename T> struct Node
{
	T data;
	Node* next;

	Node(const T& a, Node* n) : data(a), next(n) {} // 생성자
};

// <iterator> 에서 모두 제공됨
/*
template<typename Category, 
		typename T, 
		typename Distance = std::ptrdiff_t, 
		typename Pointer = T*,
		typename Reference = T&
>
struct iterator
{
	// member type 제공
	using iterator_category = forward_iterator_tag; // <iterator>, single list니까 forward
	using value_type = T;
	using pointer = Pointer;
	using Reference = T&;
	using difference_type = Distance;
};
*/

// iterator 상속
template<typename T> class slist_iterator : public iterator<forward_iterator_tag, T> 
{
	Node<T>* current = 0;
public:

	slist_iterator(Node<T>* p = 0) :current(p) {}
	slist_iterator& operator++() // 연산자 재정의 참고
	{
		current = current->next;
		return *this;
	}
	T& operator*()
	{
		return current->data;
	}
	bool operator == (const slist_iterator& it)
	{
		return current == it.current;
	}
	bool operator != (const slist_iterator& it)
	{
		return current != it.current;
	}

};


/* 알고리즘과 category */

// typename 작성시 의미있는 키워드로 작성하는 것이 좋음
template<typename InputIt, typename T>
InputIt efind(InputIt first, InputIt last, T value)
{
	while (first != last && *first != value)
		++first;
	return first;
}

int main()
{
	int x[3] = { 1,2,3 };
	int* p = efind(x, x + 3, 2);

	cout << *p << endl;


	return 0;
}