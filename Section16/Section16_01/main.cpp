#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
using namespace std;

/* Section16_01 표준 템플릿 라이브러리, 컨테이너 소개 */

// https://en.cppreference.com/w/ 찾아보기!!

void sequence_containers()
{
	//vector
	{
		vector<int> vec;  // #include <vector>
		for (int i = 0; i < 10; ++i)
			vec.push_back(i);
		// 벡터는 push_front가 없음!!

		for (auto& e : vec)
			cout << e << " ";
		cout << endl;
	}

	// deque
	{
		deque<int> deq; // #include <deque>
		for (int i = 0; i < 10; i++)
		{
			// 앞, 뒤 모두 삽입 가능
			deq.push_back(i);
			deq.push_front(i);
		}

		for (auto& e : deq)
			cout << e << " ";
		cout << endl;
	}

}

void associative_container()
{
	// set - 원소가 중복되지 않음!
	{
		set<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");

		cout << str_set.size() << endl;

		for (auto& e : str_set)
			cout << e << " ";
		cout << endl;
	}

	// multiset : 중복이 허용됨
	{
		multiset<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");

		cout << str_set.size() << endl;

		for (auto& e : str_set)
			cout << e << " ";
		cout << endl;
	}

	// map : key/value
	{
		map<char, int> map;
		map['c'] = 50;
		map['a'] = 10;
		map['b'] = 20;

		cout << map['a'] << endl;
		map['a'] = 100;
		cout << map['a'] << endl;

		// 키 순서대로 정렬되어 나옴
		for (auto& e : map)
			cout << e.first << " " <<e.second<<" ";
		cout << endl;
	}

	// map : duplicate key/value
	{
		multimap<char, int> map;
		// before c++14, pair<char, int>('a', 10) 로 삽입해야됨
		map.insert(pair<char, int>('a', 10));
		// c++17 부터는 pair('b', 20) 으로도 가능
		map.insert(pair('b', 20));
		map.insert(pair('c', 10));
		map.insert(pair('a', 100));

		cout << map.count('a') << endl;

		// 키/값 순서대로 정렬되어 나옴
		for (auto& e : map)
			cout << e.first << " " << e.second << " ";
		cout << endl;
	}
}

void container_adapters()
{
	// stack
	{
		cout << "Stack" << endl;
		stack<int> stack;
		stack.push(1);  // 복사해서 삽입하는것
		stack.emplace(2); // 새로운 객체를 만들어서 삽입하는 것
		stack.emplace(3);
		cout << stack.top() << endl;
		stack.pop();
		cout << stack.top() << endl;
	}

	// queue
	{
		cout << "Queue" << endl;
		queue<int> queue;
		queue.push(1);
		queue.push(2);
		queue.push(3);
		cout << queue.front() << " " << queue.back() << endl;
		queue.pop();
		cout << queue.front() << " " << queue.back() << endl;

	}

	// priority queue
	{
		cout << "Prioirty Queue" << endl;
		priority_queue<int> queue;
		// 값의 순서에따라 내림차순으로 삽입됨
		for (const int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
			queue.push(n);

		for (int i = 0; i < 10 ; ++i)
		{
			cout << queue.top() << endl;
			queue.pop();
		}
	}
}

int main()
{
	sequence_containers();
	cout << endl;
	associative_container();
	cout << endl;
	container_adapters();

	return 0;
}