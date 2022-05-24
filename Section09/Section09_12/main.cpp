#include <iostream>
#include <cassert>
#include <initializer_list>

using namespace std;

/* Section09_12 이니셜라이져 리스트 initializer list */

class IntArray
{
private:
	unsigned m_length = 0;
	int* m_data = nullptr;

public:
	IntArray(unsigned length) : m_length(length)
	{
		m_data = new int[length];
	}

	// 이니셜라이져 리스트
	IntArray(const std::initializer_list<int>& list) : IntArray(list.size())
	{
		int count = 0;
		for (auto& element : list)
		{
			m_data[count] = element;
			++count;
		}
	}
	
	~IntArray()
	{
		delete[] this->m_data;
	}

	friend ostream& operator << (ostream& out, IntArray& arr)
	{
		for (unsigned i = 0; i < arr.m_length; ++i)
			out << arr.m_data[i] << " ";
		out << endl;
		return out;
	}
};

int main()
{
	int my_arr1[5] = {1,2,3,4,5 };
	int* my_arr2 = new int[5]{ 1,2,3,4,5 };

	auto il = { 10,20,30 };

	IntArray int_array { 1,2,3,4,5 };
	cout << int_array << endl;

	return 0;
}