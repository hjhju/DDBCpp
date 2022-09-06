#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // for_each
#include <functional>
using namespace std;

/* Section19_01 람다(익명) 함수와 std::fuction std::bind, for_each  */

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

	// 파라미터를 뒤에 둬서 아래와 같이 사용가능
	[](const int& i) -> void { cout << "Hello " << i << endl; } (1111);

	
	{
		string name = "jackjack";
		[&]() {cout << name << endl; }();  // [&]는 영역 밖에 있는것을 레퍼런스로 가져옴, [=]는 copy해서 가져옴
	}


	// STL, for_each 과도 같이 사용 가능 
	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	auto func2 = [](int val) {cout << val << endl; };
	for_each(v.begin(), v.end(), func2);
	
	// 위와 같은 형태로 사용하기 보단 아래와 같은 형태로 많이 사용
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });


	// lambda에서 fuction type과 return type 정해주기
	cout << []()->int {return 1; }() << endl;


	// std::function은 function pointer를 체계화시켜준것, <리턴타입(매개변수 타입)>
	std::function<void(int)> func3 = func2;
	func3(123);

	// std::bind는 말 그대로 묶어 주는 것, 매개변수의 타입을 앞쪽에서 쓰지않고, bind 함수에서 사용
	std::function<void()> func4 = std::bind(func3, 456);
	func4();

	// https://en.cppreference.com/w/cpp/utility/functional/placeholders
	{
		Object instance;
		// hello는 Object의 인스턴스이므로 실행이 되기위해서는 instance가 필요, 둘의 포인터를 같이 넣어줌
		auto f1 = std::bind(&Object::hello, &instance, std::placeholders::_1);

		f1(string("World"));

		auto f2 = std::bind(&goodbye, std::placeholders::_1);
		f2(string("HJHJ"));
	}



	return 0;
}