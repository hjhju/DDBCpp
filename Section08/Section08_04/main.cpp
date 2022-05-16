#include <iostream>

using namespace std;

/* Section08_06 �Ҹ��� destructor */

	// �Ҹ��ڴ� instance�� �޸𸮿��� �����ɶ� ���ο��� �ڵ����� ȣ���
	// �����Ҵ����� ������� ��쿡�� ������ ����� �ڵ����� �޸𸮰� �������� �ʱ� ������,
	// delete�� �޸𸮸� ������ ������ �Ҹ��ڰ� ȣ���
	// �Ҹ��ڸ� ���α׷��Ӱ� ���� ȣ���ϴ� ���� ���� �������� ����


class Simple
{
	int m_id;
public:
	Simple(const int &id_in) : m_id(id_in)
	{
		cout << "Constructor " << m_id << endl;
	}

	// �Ҹ��ڴ� �Ķ���Ͱ� ����
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
	Simple *s1 = new Simple(0); //���� �Ҵ�
	Simple s2(1);

	delete s1; 

	while (true)
	{
		IntArray my_int_arr(10000);  // �Ҹ��ڰ� ������ memory leak �߻�
		
		// �Ʒ��� ���� �ۼ� �Ұ� - �Ҹ��� ����� ��ߵ�
		// delete[]my_int_arr.m_arr;
	}

	return 0;
}