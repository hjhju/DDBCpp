#include <iostream>
#include <vector>
#include <list>
using namespace std;

/* Section16_02 STL 반복자 소개 */

int main()
{
	vector<int> container;

	// list도 vector와 동일한 반복자를 사용해서 데이터 접근 가능
	//list<int> container;

	for (int i = 0; i < 10; ++i)
		container.push_back(i);

	vector<int>::const_iterator itr;
	itr = container.begin();
	while (itr != container.end())
	{
		cout << *itr << " ";
		++itr;
	}
	cout << endl;

	for (auto itr = container.begin() ; itr!=container.end() ; ++itr)
		cout << *itr << " ";
	cout << endl;

	for (auto& e : container)
		cout << e << " ";
	cout << endl;


	list<int> container2;
	for (int i = 0; i < 10; ++i)
		container.push_back(i);

	return 0;
}