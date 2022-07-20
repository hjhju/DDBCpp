#include "AutoPtr.h"
#include "Resource.h"
#include "Timer.h"

using namespace std;

/* Section15_03 �̵� �����ڿ� �̵� ���� */

AutoPtr<Resource> generateResource()
{
	AutoPtr<Resource> res(new Resource(10000000));
	return res;
}

int main()
{
	streambuf* orig_buf = cout.rdbuf();
	//cout.rdbuf(NULL); //disconnect cout from buffer
	Timer timer;

	{
		AutoPtr<Resource> main_res;
		main_res = generateResource();
	}
	
	cout.rdbuf(orig_buf); //disconnect cout from buffer
	timer.elapsed();


	return 0;
}