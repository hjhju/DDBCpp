#include <iostream>
#include "Resource.h"
using namespace std;

/* Section15_06 std::shared_ptr */

// unique_ptr���� �޸� �������� ���������� ������ �� ����
// ����� �����ϰ� �ִ��� ��!!

void soSomething(std::unique_ptr<Resource> res)
{

}

int main()
{
	// �Ķ���ͷ� ������ make_unique�� ����ϴ� ���� �� ������!! 
	//soSomething(std::unique_ptr<Resource>(new Resource(1000000)));
	soSomething(std::make_unique<Resource>(100000));

	Resource* res = new Resource(3);
	res->setAll(1);

	{
		//std::shared_ptr<Resource> ptr1(res);

		// ���� make_shared�� ����ؼ� ���������� �ʱ�ȭ�ϴ� ����� ��ȣ��
		auto ptr1 = std::make_shared<Resource>(3);
		ptr1->setAll(1);

		ptr1->print();

		{
			//std::shared_ptr<Resource> ptr2(ptr1);
			
			// ptr1�� ptr2�� res�� ���� ������ ������ ��
			// �̷��� ¥�� �ȵ�!!
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