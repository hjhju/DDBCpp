#include <iostream>
#include "Resource.h"
using namespace std;

/* Section15_06 std::shared_ptr */

// unique_ptr과는 달리 소유권을 여러곳에서 공유할 수 있음
// 몇군데서 공유하고 있는지 셈!!

void soSomething(std::unique_ptr<Resource> res)
{

}

int main()
{
	// 파라미터로 보낼때 make_unique를 사용하는 것이 더 안정적!! 
	//soSomething(std::unique_ptr<Resource>(new Resource(1000000)));
	soSomething(std::make_unique<Resource>(100000));

	Resource* res = new Resource(3);
	res->setAll(1);

	{
		//std::shared_ptr<Resource> ptr1(res);

		// 보통 make_shared를 사용해서 직접적으로 초기화하는 방식을 선호함
		auto ptr1 = std::make_shared<Resource>(3);
		ptr1->setAll(1);

		ptr1->print();

		{
			//std::shared_ptr<Resource> ptr2(ptr1);
			
			// ptr1은 ptr2가 res에 대한 소유권 가진것 모름
			// 이렇게 짜면 안됨!!
			//std::shared_ptr<Resource> ptr2(res);

			auto ptr2 = ptr1;

			ptr2->setAll(3);
			ptr2->print();

			std::cout << "going out of the block" << std::endl;
		}

		ptr1->print();

		std::cout << "going out of the outer block" << std::endl;
	}
	
	std::getchar();
	
	return 0;
}