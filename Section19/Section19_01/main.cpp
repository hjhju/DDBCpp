#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // for_each
#include <functional>
using namespace std;

/* Section19_01 ����(�͸�) �Լ��� std::fuction std::bind, for_each  */

void goodbye(const string& s)
{
	cout << "Goodbye!! " << s << endl;
}

class Object
{
public:
	void hello(const string& s)
	{
		cout << "Hello!! " << s << endl;
	}
};

int main()
{
	// 1. lambda-introducer : []
	// 2. lambda-parameter-declaration : ()
	// 3. lambda-return-type-clause : -> void
	// 4. compound-statement : {...}
	auto func = [](const int& i) -> void { cout << "Hello " << i << endl; };

	func(123);

	// �Ķ���͸� �ڿ� �ּ� �Ʒ��� ���� ��밡��
	[](const int& i) -> void { cout << "Hello " << i << endl; } (1111);

	
	{
		string name = "jackjack";
		[&]() {cout << name << endl; }();  // [&]�� ���� �ۿ� �ִ°��� ���۷����� ������, [=]�� copy�ؼ� ������
	}


	// STL, for_each ���� ���� ��� ���� 
	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	auto func2 = [](int val) {cout << val << endl; };
	for_each(v.begin(), v.end(), func2);
	
	// ���� ���� ���·� ����ϱ� ���� �Ʒ��� ���� ���·� ���� ���
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });


	// lambda���� fuction type�� return type �����ֱ�
	cout << []()->int {return 1; }() << endl;


	// std::function�� function pointer�� ü��ȭ�����ذ�, <����Ÿ��(�Ű����� Ÿ��)>
	std::function<void(int)> func3 = func2;
	func3(123);

	// std::bind�� �� �״�� ���� �ִ� ��, �Ű������� Ÿ���� ���ʿ��� �����ʰ�, bind �Լ����� ���
	std::function<void()> func4 = std::bind(func3, 456);
	func4();

	// https://en.cppreference.com/w/cpp/utility/functional/placeholders
	{
		Object instance;
		// hello�� Object�� �ν��Ͻ��̹Ƿ� ������ �Ǳ����ؼ��� instance�� �ʿ�, ���� �����͸� ���� �־���
		auto f1 = std::bind(&Object::hello, &instance, std::placeholders::_1);

		f1(string("World"));

		auto f2 = std::bind(&goodbye, std::placeholders::_1);
		f2(string("HJHJ"));
	}



	return 0;
}