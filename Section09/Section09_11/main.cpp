#include <iostream>
#include <cassert>
using namespace std;

/* Section09_11 대입 연산자 오버로딩, 깊은 복사, 얕은 복사 */

/* 
"int * ptr = new int;" 

함수 내의 지역변수 포인터인 ptr 이 동적할당 받은 어떤 int 크기의 힙 메모리를 가리키게 됨.
즉, 힙 메모리의 주소값이 할당되어 있는 ptr 은 스택 메모리에 있고 그 ptr 이 가리키는 메모리는 스택이 아닌 힙에 있는 형태가 됨.

이런 상태에서 함수가 종료된다면 지역 변수인 ptr 은 사라지되 ptr 이 주소값으로 가지고 있던 해당 주소의 힙 메모리는 종료되지 않음.
해당 힙 메모리의 주소를 가지고 있던 ptr 이 사라졌으니 이제 이 힙메모리에 접근할 방법은 사라짐. 
분명 힙 메모리에 자리는 차지 하고 있는데 주소를 잃어버려서 찾지 못하게 되는 것. 이런 현상을 메모리 누수라고함.
*/

class MyString
{
public:
	char* m_data = nullptr;
	int m_length = 0;

public:
	MyString(const char* source = "")
	{
		// 문자열이 비어있지 않은지 체크
		assert(source);

		m_length = std::strlen(source) + 1;
		m_data = new char[m_length]; 

		for (int i = 0; i < m_length; ++i)
			m_data[i] = source[i];

		m_data[m_length - 1] = '\0';

	}

	~MyString()
	{
		delete[] m_data;
	}

	MyString(const MyString& source)
	{
		cout << "Copy constructor " << endl;
		m_length = source.m_length;

		// 깊은 복사!!
		if (source.m_data != nullptr)
		{
			m_data = new char[m_length]; // 메모리 할당 후

			for (int i = 0; i < m_length; ++i) 
				m_data[i] = source.m_data[i]; // 내용 복사
		}
		else
			m_data = nullptr;
	}

	MyString& operator = (const MyString& source)
	{
		/* shallow copy */
		//this->m_data = source.m_data;
		//this->m_length = source.m_length;

		cout << "Assignment operator" << endl;

		if (this == &source) // prevent self-assignment
			return *this;

		delete[] m_data;

		m_length = source.m_length;

		if (source.m_data != nullptr)
		{
			m_data = new char[m_length]; // 메모리 할당 후

			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i]; // 내용 복사
		}
		else
			m_data = nullptr;

		return *this;
	}

	char* getString() { return m_data; }
	int getLength() { return m_length; }
};

int main()
{
	MyString hello("Hello");
	cout << (int*)hello.m_data << endl;
	cout << hello.getString() << endl;

	{
		MyString copy = hello; // copy constructor
		cout << (int*)copy.m_data << endl;
		cout << copy.getString() << endl;
	}

	cout << hello.getString() << endl;
	cout << endl;

	MyString str1 = hello; // copy
	MyString str2;
	str2 = hello; // assignment



	return 0;
}