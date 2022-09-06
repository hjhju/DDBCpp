#include <iostream>
#include <future> // async
#include <thread>
using namespace std;

/* Section19_05 작업기반 비동기 프로그래밍  */

int main()
{
	// multi-threading
	{
		int result;
		std::thread t1([&] {result = 1 + 2; });
		t1.join();
		cout << result << endl;
	}

	// task-based parallelism
	{
		// std::future<int> fut 
		auto fut1 = std::async([] {return 1 + 2; }); // 비동기적
		cout << fut1.get() << endl;
	}

	//future and promise
	{
		std::promise<int> prom;
		auto fut2 = prom.get_future();
		// future를 받을 수 있는 존재가 필요해서 promise를 거쳐가도록 함
		// promise를 파라미터로 넣어 주어야함!!
		auto t2 = std::thread([](std::promise<int>&& prom) 
		{
			prom.set_value(1 + 2);  // prom가 set_value를 통해 값을 받을때 까지 fut2가 기다림
		}, std::move(prom));
		cout << fut2.get() << endl;
		t2.join();
	}

	// thread와 async의 차이
	// async를 thread로 바꿔보면 join이 없을 때 xxx end가 출력이 되지 않음

	// async를 받아주는 future가 없다면 그냥 sequential하게 실행됨
	{
		auto f1 = std::async([] {
		//auto f1 = std::thread([] {
		//std::async([] {
			cout << "async1 start" << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "async1 end" << endl;
		});
		
		auto f2 = std::async([] {
		//auto f2 = std::thread([] {
		//std::async([] {
			cout << "async2 start" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "async2 end" << endl;
		});

		//f1.join();
		//f2.join();

		std::cout << "Main function" << endl;
	}


	return 0;
}