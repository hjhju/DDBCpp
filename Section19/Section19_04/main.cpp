#include <iostream>
#include <thread>
#include <atomic> // �ɰ��� ���ٴ� �ǹ�, operation�� ������ �ѹ��� �ذ��Ҽ��ֵ��� ���� �۾�
#include <mutex>
#include <chrono>

using namespace std;

/* Section19_04 ���̽� �����, std::atomic, std::scoped_lock  */

// ���̽� ����� : ���� �ڿ��� ���� ���� ���� ���μ����� ���ÿ� �����ϱ� ���� �����ϴ� ���¸� �ǹ�
// ���� �޸� ������ ����ϱ⶧���� �������� �߻��� �� ����

// ���̽� ����� �ذ�
// 1. atomic ���
// 2. mutex ���
// 3. std::lock_guard �Ǵ� std::scoped_lock ���

int shared_memory(0);
//atomic<int> shared_memory(0);

mutex mtx;

int main()
{
	auto count_func = []() {
		for (int i = 0; i < 100; i++)
		{
			// ��� ������ ���ؼ� �ٸ� thread�� ������ �� �� ����
			this_thread::sleep_for(chrono::milliseconds(1)); 

			//std::lock_guard lock(mtx);  // c++17 ����, ������ ������ Ǯ���Ƿ� unlock�� �ʿ����� ����
			std::scoped_lock lock(mtx); // c++17 ����, lock_guard���� �� ����Ǵ� ��� 

			shared_memory++;

			//shared_memory.fetch_add(1);  // ++�� ���� �ǹ�, race conditiond�� �ذ������� ���� �� ����
		}
			
	};

	thread t1 = thread(count_func);
	thread t2 = thread(count_func);
	thread t3 = thread(count_func);

	t1.join();
	t2.join();
	t3.join();

	cout << "After" << endl;
	cout << shared_memory << endl; 
	// atomic�� �� �پ������� shared_memory���� 300�� ������ ����
	// ���� : ������� t1�� cpu�� �о���� ����, t2�� ���� �÷������� t1�� �ϴ� ������ �ݿ���������

	return 0;
}