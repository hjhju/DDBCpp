#include <iostream>
#include <thread>
#include <future>
#include <chrono>

using namespace std;
using namespace std::literals;

/* 01_std::promise */
// promise�� ������ ���̿��� �� �Ǵ� ���ܸ� ������ �� �ִ� ���ø�
// promise�� ���ؼ� ���޵� �����ʹ� std::future�� ���� ���� �� ����
// ������ ������ promise ��ü�� ����(&, &&)�� ���� �Ѵ�.

void add(std::promise<int>&& p, int a, int b)
{
	int s = a + b;
	std::this_thread::sleep_for(1s);
	//p.set_value(s);

	p.set_value_at_thread_exit(s);
	cout << "add" << endl;
	std::this_thread::sleep_for(1s);

}

void divide(std::promise<int>&& p, int a, int b)
{
	try
	{
		if (b == 0)
			throw std::runtime_error("divide by zero");
		p.set_value(a / b);
	}
	catch(...)
	{
		//p.set_exception(std::current_exception()); // ���� �߻��� ���ܸ� ������ �� �����忡 �˷���
		p.set_exception_at_thread_exit(std::current_exception());
	}
}

int main()
{
	std::promise<int> pm;
	std::future<int> ft = pm.get_future();

	//std::thread t(add, std::move(pm), 10, 20);
	//int ret = ft.get(); // blocking
	//cout << ret << endl;
	//t.join();

	std::thread t(divide, std::move(pm), 10, 0);

	try
	{
		int ret = ft.get();
	}
	catch (std::exception& e)
	{
		cout << e.what() << endl;
	}
	t.join();
	
	

	return 0;
}