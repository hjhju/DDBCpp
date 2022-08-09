#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Section16_03 STL �˰��� �Ұ� */

int main()
{
	vector<int> container;
	for (int i = 0; i < 10; i++)
		container.push_back(i);

	// #include <algorithm>
	auto itr = min_element(container.begin(), container.end());
	cout << *itr << endl;

	itr = max_element(container.begin(), container.end());
	cout << *itr << endl;

	itr = find(container.begin(), container.end(), 3);
	cout << *itr << endl;
	container.insert(itr, 128); // 3�� �ڸ��� 128�� ����, 3�� ��ĭ �ڷ� �и�

	for (auto& e : container)
		cout << e << " ";
	cout << endl;

	sort(container.begin(), container.end());
	// �Ǵ�
	//container.sort();

	for (auto& e : container)
		cout << e << " ";
	cout << endl;

	reverse(container.begin(), container.end());

	for (auto& e : container)
		cout << e << " ";
	cout << endl;


	return 0;
}