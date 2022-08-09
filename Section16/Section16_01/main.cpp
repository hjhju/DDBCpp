#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
using namespace std;

/* Section16_01 ǥ�� ���ø� ���̺귯��, �����̳� �Ұ� */

// https://en.cppreference.com/w/ ã�ƺ���!!

void sequence_containers()
{
	//vector
	{
		vector<int> vec;  // #include <vector>
		for (int i = 0; i < 10; ++i)
			vec.push_back(i);
		// ���ʹ� push_front�� ����!!

		for (auto& e : vec)
			cout << e << " ";
		cout << endl;
	}

	// deque
	{
		deque<int> deq; // #include <deque>
		for (int i = 0; i < 10; i++)
		{
			// ��, �� ��� ���� ����
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
	// set - ���Ұ� �ߺ����� ����!
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

	// multiset : �ߺ��� ����
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

		// Ű ������� ���ĵǾ� ����
		for (auto& e : map)
			cout << e.first << " " <<e.second<<" ";
		cout << endl;
	}

	// map : duplicate key/value
	{
		multimap<char, int> map;
		// before c++14, pair<char, int>('a', 10) �� �����ؾߵ�
		map.insert(pair<char, int>('a', 10));
		// c++17 ���ʹ� pair('b', 20) ���ε� ����
		map.insert(pair('b', 20));
		map.insert(pair('c', 10));
		map.insert(pair('a', 100));

		cout << map.count('a') << endl;

		// Ű/�� ������� ���ĵǾ� ����
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
		stack.push(1);  // �����ؼ� �����ϴ°�
		stack.emplace(2); // ���ο� ��ü�� ���� �����ϴ� ��
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
		// ���� ���������� ������������ ���Ե�
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