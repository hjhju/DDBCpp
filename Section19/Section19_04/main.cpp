#include <iostream>
#include <thread>
#include <atomic> // 쪼갤수 없다는 의미, operation의 행위를 한번에 해결할수있도록 묶는 작업
#include <mutex>
#include <chrono>

using namespace std;

/* Section19_04 레이스 컨디션, std::atomic, std::scoped_lock  */

// 레이스 컨디션 : 공유 자원에 대해 여러 개의 프로세스가 동시에 접근하기 위해 경쟁하는 상태를 의미
// 같은 메모리 공간을 사용하기때문에 문제점이 발생할 수 있음

// 레이스 컨디션 해결
// 1. atomic 사용
// 2. mutex 사용
// 3. std::lock_guard 또는 std::scoped_lock 사용

int shared_memory(0);
//atomic<int> shared_memory(0);

mutex mtx;

int main()
{
	auto count_func = []() {
		for (int i = 0; i < 100; i++)
		{
			// 잠시 쉼으로 인해서 다른 thread가 접근할 수 도 있음
			this_thread::sleep_for(chrono::milliseconds(1)); 

			//std::lock_guard lock(mtx);  // c++17 지원, 영역이 지나면 풀리므로 unlock이 필요하지 않음
			std::scoped_lock lock(mtx); // c++17 지원, lock_guard보다 더 권장되는 방식 

			shared_memory++;

			//shared_memory.fetch_add(1);  // ++과 같은 의미, race conditiond은 해결하지만 조금 더 느림
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
	// atomic이 안 붙어있을때 shared_memory값은 300이 나오지 않음
	// 사유 : 예를들어 t1이 cpu로 읽어들인 사이, t2가 값을 올려버리면 t1가 하는 행위는 반영되지않음

	return 0;
}