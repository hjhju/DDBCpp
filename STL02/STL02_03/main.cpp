#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

/* STL Example */

int main()
{
	//list<int> s = { 1, 2, 3, 4, 5 };
	vector<int> s = { 1, 2, 3, 4, 5 };

	reverse(s.begin(), s.end());

	// [] 연산자는 vector등 일부만 가능, list는 안됨
	for (int i = 0; i < s.size(); i++)
		cout << s[i] << " ";
	cout << endl;


	vector <int>::iterator p = s.begin();
	while (p != s.end())
	{
		cout << *p << endl;
		++p;
	}


	for (auto& n : s) //복사본이 염려되면 참조로 받기!!
		cout << n << endl;


	return 0;
}