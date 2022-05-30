#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <shared_mutex>
#include <queue>

using namespace std::literals;

std::shared_mutex m;
std::mutex qm;
int share_data = 0;
std::queue<int> q;

void producer()
{
    while (1)
    {
        m.lock();
        share_data = (share_data + 1) % 1000;

        if (q.size() < 1000) {
            q.push(share_data);
        }
        else {
            std::this_thread::sleep_for(1s);
        }       
        m.unlock();
        std::this_thread::sleep_for(1ms);
    }
}

void consumer()
{
    while (1)
    {
        int qp = -1;
        int qs = 0;
        m.lock_shared();

        qm.lock();
        if (q.size() >= 100) {
            qp = q.front();
            q.pop();
            qs = q.size();
        }
        qm.unlock();

        if (qp != -1) {
            std::cout <<std::this_thread::get_id() << " : pop=" << qp << ", qsize=" << qs << std::endl;
        }

        m.unlock_shared();
        std::this_thread::sleep_for(10ms);
    }
}


int main()
{
	std::thread t1(producer);
	std::thread t2(consumer);
	std::thread t3(consumer);
	std::thread t4(consumer);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	return 0;
}