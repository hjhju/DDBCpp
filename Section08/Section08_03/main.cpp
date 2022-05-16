#include <iostream>
#include <string>
using namespace std;

/* Section08_04 생성자 멤버 초기화 목록 */
// 생성자 뒤에 : 를 붙이고 멤버 초기화 시킬수 있음

/* Section08_05 위임 생성자 */
// 위임 생성자 : 생성자가 다른 생성자를 사용하는 것

class B
{
private:
	int m_b;

public:
	B(const int& m_b_in) : m_b(m_b_in)
	{

	}
	int print()
	{
		return m_b;
	}
};

class Something
{
	// 생성자가 존재할때는 생성자에서 초기화된 내용이 우선시됨!!
private:
	int m_i = 10;
	double m_d =10.0;
	char m_c = 'f';
	int m_arr[5] = { 10,20,30,40,50 };
	B m_b{ 1024 };

public:
	Something() : m_i{ 1 }, m_d{ 3.14 }, m_c{ 'a' }, m_arr{ 1,2,3,4,5 }, m_b(m_i-1)
	{
		m_i = 2;
		m_d = 3.28;
		m_c = 'b';
	}

	void print()
	{
		cout << m_i << " " << m_d << " " << m_c <<endl;
		for (auto& e : m_arr)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << m_b.print() << endl;
	}
};

class Student
{
private:
	int m_id;
	string m_name;
public:

	// 방법 1
	// 중복 초기화 없이 다음과 같이 생성자 작성 가능, 위임 생성자!! (c++11 이후로 가능)
	Student(const string& name_in) : Student(0, name_in)
	{

	}

	Student(const int& id_in, const string& name_in) : m_id(id_in), m_name(name_in)
	{
		
	}

	// 방법 2 (예전 방식)
	// 초기화 코드를 분리 -> 각 생성자에 init(0, name_in), init(id_in, name_in) 넣어 주기
	void init(const int& id_in, const string& name_in)
	{
		m_id = id_in;
		m_name = name_in;
	}

	void print()
	{
		cout << m_id << " " << m_name << endl;
	}
};

int main()
{
	Something sth;
	sth.print();
	cout << endl;

	Student stu1(11, "jack jack");
	stu1.print();

	Student stu2("kim");
	stu2.print();


	return 0;
}