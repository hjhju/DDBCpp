#include <iostream>
#include <array>
#include <algorithm>


using namespace std;

/* Section06_20 std::array 소개   */


void printArray(const array<int, 5> &arr)
{
	cout << arr.size() << endl;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	
	array<int, 5> my_Arr = { 1, 21, 3, 40, 15 };

	cout << my_Arr[0] << endl;
	cout << my_Arr.at(0) << endl;
	cout << my_Arr.size() << endl;

	printArray(my_Arr);

	for (auto num : my_Arr)
		cout << num << " ";
	cout << endl;

	// algorithm에서 쓸 수 있음
	std::sort(my_Arr.begin(), my_Arr.end());
	for (auto num : my_Arr)
		cout << num << " ";
	cout << endl;

	std::sort(my_Arr.rbegin(), my_Arr.rend());
	for (auto num : my_Arr)
		cout << num << " ";
	cout << endl;

	return 0;
}