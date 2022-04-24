#include <iostream>
#include <vector>

using namespace std;

/* Section06_21 std::vector 소개   */


int main()
{
	// 벡터는 메모리를 알아서 지워줌

	vector<int> arr1 = { 1, 2, 3, 4, 5 };
	cout << arr1.size() << endl;

	vector<int> arr2 = { 1, 2, };
	cout << arr2.size() << endl;

	for (auto& itr : arr1)
		cout << itr << " ";
	cout << endl;

	cout << arr1[1] << endl;
	cout << arr1.at(1) << endl;

	// 크기 바꿀 수 있음
	arr1.resize(10);
	cout << arr1.size() << endl;
	for (auto& itr : arr1)
		cout << itr << " ";
	cout << endl;

	return 0;
}