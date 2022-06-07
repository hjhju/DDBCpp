#include <iostream>
#include <initializer_list>

using namespace std;

/* Section10_06 컨테이너 클래스 */

// 컨테이너 클래스 : 다른 클래스를 담는 역할을 하는 클래스

class IntArray
{
private:
	int m_length = 0;
	int* m_data = nullptr;

public:
	//constructors
	IntArray(const int& length_in) : m_length(length_in) 
	{
		initialize(m_length);
	}

	IntArray(const std::initializer_list<int> &list) : IntArray(list.size())
	{
		int i = 0;
		for (auto& e : list)
		{
			m_data[i++] = e;
		}
	}

	//destructors
	~IntArray()
	{
		delete[] m_data;
	}

	void initialize(const int& length_in)
	{
		m_data = new int[length_in];
	}

	void reset()
	{
		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}

	IntArray& resize(const int& length_in)
	{
		if (m_length == length_in)
			return *this;
		else if (m_length < length_in)
		{
			int* temp = new int[length_in];
			for (int i = 0; i < m_length; i++)
				temp[i] = m_data[i];
			for (int i = m_length; i < length_in; i++)
				temp[i] = 0;

			m_length = length_in;
			delete[] m_data;
			m_data = temp;
		}
		else
		{
			m_length = length_in;
			int* temp = new int[m_length];
			for (int i = 0; i < m_length; i++)
				temp[i] = m_data[i];

			delete[] m_data;
			m_data = temp;
		}
		
		return *this;
	}

	void insertBefore(const int& value, const int& ix)
	{
		resize(m_length + 1);
		for(int i = m_length-1; i > ix; i--)
			m_data[i] = m_data[i - 1];
		m_data[ix] = value;
	}

	void remove(const int& ix)
	{
		for (int i = ix; i < m_length; i++)
			m_data[i] = m_data[i+1];
		resize(m_length - 1);
	}
	
	void push_back(const int& value)
	{
		resize(m_length + 1);
		m_data[m_length - 1] = value;
	}

	friend ostream& operator << (ostream& out, const IntArray& int_arr)
	{
		for (int i = 0; i < int_arr.m_length; i++)
			out << int_arr.m_data[i] << " ";

		return out;
	}
};

int main()
{
	IntArray my_arr{1,3,5,7,9};
	cout << my_arr << endl;

	my_arr.insertBefore(10, 1); // 1, 10, 3, 5, 7, 9
	cout << my_arr << endl;

	my_arr.remove(3); // 1, 10, 3, 7, 9
	cout << my_arr << endl;

	my_arr.push_back(13); //1, 10, 3, 7, 9, 13
	cout << my_arr << endl;

	return 0;
}