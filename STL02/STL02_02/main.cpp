#include <iostream>

using namespace std;

/* make container */
/* make iterator */


template<typename T1, typename T2>
T1 efind(T1 first, T1 last, T2 vlaue)
{
	while (first != last && *first != vlaue)
	{
		++first;
	}
	return first;
}

template<typename T> struct Node
{
	T data;
	Node* next;

	Node(const T& a, Node* n) : data(a), next(n) {} // 생성자
};


template<typename T> class slist_iterator
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


template<typename T> class slist
{
public :
	Node<T>* head = 0;
	void push_front(const T& a) 
	{
		head = new Node<T>(a, head); 
	}

	using iterator = slist_iterator<T>;

	iterator begin()
	{
		return iterator(head);
	}
	iterator end()
	{
		return iterator(0);
	}

};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	// 반복자의 타입 이름은 "컨테이너이름::iterator"로 접근
	slist<int>::iterator p = s.begin();

	cout << *p << endl;
	++p;
	cout << *p << endl;

	while (p != s.end())
	{
		cout << *p << endl;
		++p;
	}

	// 앞서 생성한 efind 활용한 검색
	slist<int>::iterator p2 = efind(s.begin(), s.end(), 20);

	if(p2 == s.end())
		cout << "fail" << endl;
	else
		cout << "success : " << *p2 << endl;


	return 0;
}