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

	// [] �����ڴ� vector�� �Ϻθ� ����, list�� �ȵ�
	for (int i = 0; i < s.size(); i++)
		cout << s[i] << " ";
	cout << endl;


	vector <int>::iterator p = s.begin();
	while (p != s.end())
	{
		cout << *p << endl;
		++p;
	}


	for (auto& n : s) //���纻�� �����Ǹ� ������ �ޱ�!!
		cout << n << endl;


	return 0;
}