#include <iostream>
#include <memory>
using namespace std;

/* Section14_06 ����ó���� ���輺�� ���� */

// �׷��� �ɷ���(������) �� �ִ� ���� if������ �ɷ����°� ���� 

class A
{
public:
	// destructor������ ���ܸ� ���� �� ����!!!
	~A()
	{
		throw "error";
	}
};

int main()
{
	try
	{
		// ���� �Ҵ��� ���
		int* i = new int[100000];

		// ������ ����� unique_ptr�� �˾Ƽ� delete�� - memory leak ���� �� ����
		//unique_ptr<int> up_i(i);
		
		throw "Error";

		delete[] i;

		// �Ҹ��ڿ����� ����ó�� �ȵ�!!
		// A a;

	}
	catch (...)
	{
		cout << "Catch" << endl;
	}

	return 0;

}