#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Section16_03 STL 알고리즘 소개 */

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
	container.insert(itr, 128); // 3의 자리에 128을 넣음, 3은 한칸 뒤로 밀림

	for (auto& e : container)
		cout << e << " ";
	cout << endl;

	sort(container.begin(), container.end());
	// 또는
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