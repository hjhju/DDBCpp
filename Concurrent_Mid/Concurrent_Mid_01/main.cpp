#include <iostream>
#include <thread>
#include <future>
#include <chrono>

using namespace std::literals;

void add(std::promise<int>&& p, int a, int b)
{
	int s = 0;
	for (int i = a; i < b + 1; i++)
	{
		s += i;
	}
	p.set_value(s);
}

int main()
{
	std::promise<int> pm;
	std::future<int> ft = pm.get_future();

	std::thread t(add, std::move(pm), 1, 1000);

	int ret = ft.get();
	std::cout << ret << std::endl;
	t.join();

	return 0;
}