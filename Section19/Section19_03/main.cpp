#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>
using namespace std;

/* Section19_03 std::thread�� ��Ƽ������ ����  */

// process : os�� �����Ҷ� �۵��ϴ� ��
// �ϳ��� process�� �������� thread�� �����Ѵ�.
// ��Ƽ������ : �ϳ��� cpu���� �������� thread�� ���ÿ� �۾�
// ��Ƽ�������� ��Ƽ ���μ��̺��� ȿ����


mutex mtx; // mutual exclusion (��ȣ ����)

int main()
{
	// �ϵ���� �ھ� �� ���
	const int num_pro = std::thread::hardware_concurrency();
	cout << num_pro << endl;

	// this thread�� id�� ���
	cout << std::this_thread::get_id() << endl;

	// �ؾ��� ���� �Ű������� �ָ� ��
	// ���λ��� thread�� ���� thread�� ������ �ؾ��� -> join�̿�

	/*
	std::thread t1 = std::thread([]() { 
		cout << std::this_thread::get_id() << endl; 
		while (true) {}});

	std::thread t2 = std::thread([]() {
		cout << std::this_thread::get_id() << endl;
		while (true) {}});

	std::thread t3 = std::thread([]() {
		cout << std::this_thread::get_id() << endl;
		while (true) {}});

	std::thread t4 = std::thread([]() {
		cout << std::this_thread::get_id() << endl;
		while (true) {}});

	t1.join(); // t1�� ������ ���� ��ٷ���
	t2.join();
	t3.join();
	t4.join();

	*/

	/*
	vector<std::thread> my_threads;
	my_threads.resize(num_pro);
	
	for (auto& e : my_threads)
	{
		e = std::thread([]() {
			cout << std::this_thread::get_id() << endl;
			while (true) {}});
	}

	for (auto& e : my_threads)
		e.join();

	*/


	auto work_func = [](const string& name) {
		for (int i = 0; i < 5; i++)
		{
			// ��� ���� �ϱ�
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			// mutex�� lock, unlock ���� ��ߵ�
			mtx.lock();
			cout << name << " " << std::this_thread::get_id() << " is working " << i << endl;
			mtx.unlock();
		}
	};

	// �̷��Ը� �ϸ� �� �����常 ���
	//work_func("JackJack");
	//work_func("Dash");

	std::thread t1 = std::thread(work_func, "JackJack");
	std::thread t2 = std::thread(work_func, "Dash");
	std::thread t3 = std::thread(work_func, "Kim");

	t1.join();
	t2.join();
	t3.join();



	return 0;
}