#include <iostream>
#include <memory>  // unique pointer
#include "Resource.h"
using namespace std;

/* Section15_05 std::unique_ptr */

// 포인터가 가리키고 있는 데이터의 소유권이 한곳에만 속할때 사용하는 스마트 포인터

auto doSomething()
{
	//auto res1 = std::make_unique<Resource>(5);
	//return res1;

	return std::unique_ptr<Resource>(new Resource(5));

	// return std::make_unique<Resource>(5);
}


//void doSomething2(std::unique_ptr<Resource> &res)
//auto doSomething2(std::unique_ptr<Resource> res)
void doSomething2(Resource* res)
{
	res->setAll(10);
	res->print();

	//return res;
}

int main()
{
	{
		//Resource* res = new Resource(10000000);

		// unique_ptr은 생성, 소멸 자동으로 해줌
		//std::unique_ptr<Resource> res(new Resource(10000000));

		// early return or throw

		//delete res;
	}

	//{
	//	std::unique_ptr<int> upi(new int);

		//auto* ptr = new Resource(5);
		//std::unique_ptr<Resource> res1(ptr);
	// 1)
	//	std::unique_ptr<Resource> res1(new Resource(5));
	// 2)
	//	auto res1 = std::make_unique<Resource>(5);
	// 3)
	//	auto res1 = doSomething();

	//	res1->setAll(5);
	//	res1->print();

	//	std::unique_ptr<Resource> res2;
	//	std::cout << std::boolalpha;
	//	std::cout << static_cast<bool>(res1) << std::endl;
	//	std::cout << static_cast<bool>(res2) << std::endl;

	//	// uniqu_ptr 은 소유권이 한곳에만 있을 수 있기에 copy sementic은 사용할 수 없음
	//	//res2 = res1;
	//	res2 = std::move(res1);
	//	std::cout << std::boolalpha;
	//	std::cout << static_cast<bool>(res1) << std::endl;
	//	std::cout << static_cast<bool>(res2) << std::endl;

	//	if (res1 != nullptr) res1->print();
	//	if (res2 != nullptr) res2->print();

	////}

	{
		auto res1 = std::make_unique<Resource>(5);
		res1->setAll(1);
		res1->print();

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;

		// doSomething2(std::unique_ptr<Resource> & res) 일때
		//doSomething2(res1);
		
		// doSomething2(std::unique_ptr<Resource> res) 일때
		//res1 = doSomething2(std::move(res1));

		// doSomething2(Resource* res) 일때
		// unique_ptr은 자체적으로 get() 을 가지고 있음
		doSomething2(res1.get());

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;

		res1->print();
	}

	{
		// 아래와 같이 작성하면 안됨!!!
		//Resource* res = new Resource;
		//std::unique_ptr<Resource> res1(res);
		//std::unique_ptr<Resource> res2(res); // X

		//delete res; // X
	}


	return 0;
}