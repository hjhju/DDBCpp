#include <iostream>
#include <string>
using namespace std;

/* Section08_09 클래스와 const */

class Something
{
public:
	int m_id = 0;

	Something(const Something& st_in)
	{
		m_id = st_in.m_id;

		cout << "Copy Constructor " << endl;
	}

	Something()
	{
		cout << "Constructor " << endl;
	}

	void setID(int id) { m_id = id; }

	int getID() const
	{ 
		return m_id;
	}
};

class Something2
{
public:
	string m_value = "default";

	// const를 기준으로 오버로딩 가능!!

	const string& getValue() const 
	{
		cout << "const ver" << endl;
		return m_value; //const reference를 리턴
	}

	string& getValue()
	{
		cout << "non-const ver" << endl;
		return m_value; //non-const reference를 리턴
	}
};

// 매개변수로 구현되어 있지 않은 copy constructor가 실행됨
// 즉 st가 복사되어 들어감

// const Something &st의 경우 복사는 일어나지 않음 - 주소값도 동일
void print(const Something &st)
//void print(Something st)
{
	cout << &st << endl;

	cout << st.m_id << endl;
}

int main()
{
	//Something something;

	const Something something;

	// 객체 생성시 const를 붙이면 아래 코드는 오류가 남
	// something을 const로 만든다는 것은 m_id를 const로 만든것과 같은 효과
	// m_id의 값을 바꾸려는 setID의 호출이 오류 유발
	
	//something.setID(3);

	// 멤버 함수에 const를 붙이면 아래 코드는 가능
	cout << something.getID() << endl;

	cout << &something << endl;

	print(something);

	cout << endl;

	Something2 some1;
	some1.getValue();
	some1.getValue() = 10;


	const Something2 some2;
	some2.getValue();
	// some2.getValue() = 20; // 안됨!


	return 0;
}