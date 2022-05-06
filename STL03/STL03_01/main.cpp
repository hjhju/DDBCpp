#include <iostream>
#include <list>
#include <vector>
//#include <experimental/filesystem>

using namespace std;
//using namespace std::experimental::filesystem;

/* iterator basic  */

// iterator in GoF's Design Pattern 
// ���� ��ü�� ���� ������ ������� ���������� ��ҿ� �����ϱ� ���� ����� �����ϴ� ��

// iterator in STL
// �ݺ��� ó�� �����ϴ� ��� ���� �ݺ����̴�.
// ++�����ڷ� �̵������ϰ�, *�����ڷ� ��ҿ� ���� ������ �� 

int main()
{
	int x[5] = { 1,2,3,4,5 };
	int* p = x;
	cout << *p << endl;
	cout << *(++p) << endl;

	//list<int> s = { 1,2,3,4,5 };
	vector<int> s = { 1,2,3,4,5 };
	//list<int>::iterator p2 = s.begin();
	//cout << *p2 << endl;
	//cout << *(++p2) << endl;

	// c++17���� ����
	//directory_iterator p3("C://windows");
	//cout << *p3 << endl;
	//cout << *(++p3) << endl;

	// �����̳ʿ��� �ݺ��� ������
	// c++11 ���� auto ��� ����
	auto p4 = s.begin(); // ��¥ �迭�� error

	auto p5 = begin(x);
	int n = size(x);
	cout << *p5 << endl;
	cout << n << endl;

	auto p6 = end(x);
	cout << *p6 << endl; // ������ ������ ����Ŵ error


	// �ݺ����� ��ȿȭ 
	s.resize(100);
	cout << *p4 << endl; // ���� ���Ҵ� error, ��ȿȭ�� �ݺ���



	return 0;
}