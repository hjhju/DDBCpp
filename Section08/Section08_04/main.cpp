#include <iostream>

using namespace std;

/* Section08_06 소멸자 destructor */

	// 소멸자는 instance가 메모리에서 해제될때 내부에서 자동으로 호출됨
	// 동적할당으로 만들어진 경우에는 영역을 벗어나도 자동으로 메모리가 해제되지 않기 때문에,
	// delete로 메모리를 해제할 때에만 소멸자가 호출됨
	// 소멸자를 프로그래머가 직접 호출하는 것은 거의 권장하지 않음


class Simple
{
	int m_id;
public:
	Simple(const int &id_in) : m_id(id_in)
	{
		cout << "Constructor " << m_id << endl;
	}

	// 소멸자는 파라미터가 없음
	~Simple()
	{
		cout << "Destructor " << m_id << endl;
	}
};

class IntArray
{
private:
	int* m_arr = nullptr;
	int m_length = 0;

public:
	IntArray(const int length_in)
	{
		m_length = length_in;
		m_arr = new int[m_length];

		cout << "Constructor " << endl;

	}

	~IntArray()
	{
		if (m_arr != nullptr)
			delete[]m_arr;
	}

	int size()
	{
		return m_length;
	}
};

int main()
{
	//Simple s1(0);
	Simple *s1 = new Simple(0); //동적 할당
	Simple s2(1);

	delete s1; 

	while (true)
	{
		IntArray my_int_arr(10000);  // 소멸자가 없으면 memory leak 발생
		
		// 아래와 같이 작성 불가 - 소멸자 만들어 줘야됨
		// delete[]my_int_arr.m_arr;
	}

	return 0;
}