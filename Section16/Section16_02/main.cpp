#include <iostream>
#include <vector>
#include <list>
using namespace std;

/* Section16_02 STL �ݺ��� �Ұ� */

int main()
{
	vector<int> container;

	// list�� vector�� ������ �ݺ��ڸ� ����ؼ� ������ ���� ����
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