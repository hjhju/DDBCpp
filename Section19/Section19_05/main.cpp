#include <iostream>
#include <future> // async
#include <thread>
using namespace std;

/* Section19_05 �۾���� �񵿱� ���α׷���  */

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
		auto fut1 = std::async([] {return 1 + 2; }); // �񵿱���
		cout << fut1.get() << endl;
	}

	//future and promise
	{
		std::promise<int> prom;
		auto fut2 = prom.get_future();
		// future�� ���� �� �ִ� ���簡 �ʿ��ؼ� promise�� ���İ����� ��
		// promise�� �Ķ���ͷ� �־� �־����!!
		auto t2 = std::thread([](std::promise<int>&& prom) 
		{
			prom.set_value(1 + 2);  // prom�� set_value�� ���� ���� ������ ���� fut2�� ��ٸ�
		}, std::move(prom));
		cout << fut2.get() << endl;
		t2.join();
	}

	// thread�� async�� ����
	// async�� thread�� �ٲ㺸�� join�� ���� �� xxx end�� ����� ���� ����

	// async�� �޾��ִ� future�� ���ٸ� �׳� sequential�ϰ� �����
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