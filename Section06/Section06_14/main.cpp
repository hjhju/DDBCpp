#include <iostream>
#include <vector>

using namespace std;

/* Section06_21 std::vector �Ұ�   */


int main()
{
	// ���ʹ� �޸𸮸� �˾Ƽ� ������

	vector<int> arr1 = { 1, 2, 3, 4, 5 };
	cout << arr1.size() << endl;

	vector<int> arr2 = { 1, 2, };
	cout << arr2.size() << endl;

	for (auto& itr : arr1)
		cout << itr << " ";
	cout << endl;

	cout << arr1[1] << endl;
	cout << arr1.at(1) << endl;

	// ũ�� �ٲ� �� ����
	arr1.resize(10);
	cout << arr1.size() << endl;
	for (auto& itr : arr1)
		cout << itr << " ";
	cout << endl;

	return 0;
}