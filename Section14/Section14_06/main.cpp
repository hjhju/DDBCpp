#include <iostream>
#include <memory>
using namespace std;

/* Section14_06 예외처리의 위험성과 단점 */

// 그래도 걸러낼(예측할) 수 있는 것은 if문으로 걸러내는게 좋음 

class A
{
public:
	// destructor에서는 예외를 던질 수 없음!!!
	~A()
	{
		throw "error";
	}
};

int main()
{
	try
	{
		// 동적 할당의 경우
		int* i = new int[100000];

		// 영역을 벗어나면 unique_ptr는 알아서 delete됨 - memory leak 잡을 수 있음
		//unique_ptr<int> up_i(i);
		
		throw "Error";

		delete[] i;

		// 소멸자에서는 예외처리 안됨!!
		// A a;

	}
	catch (...)
	{
		cout << "Catch" << endl;
	}

	return 0;

}