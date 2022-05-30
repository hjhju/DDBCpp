#include <iostream>
#include <thread>
#include <future>
#include <chrono>

using namespace std;
using namespace std::literals;

/* 01_std::promise */
// promise는 스레드 사이에서 값 또는 예외를 공유할 수 있는 템플릿
// promise를 통해서 전달된 데이터는 std::future를 통해 얻을 수 있음
// 스레드 생성시 promise 객체를 참조(&, &&)로 전달 한다.

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
		//p.set_exception(std::current_exception()); // 현재 발생한 예외를 꺼내서 주 스레드에 알려줌
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