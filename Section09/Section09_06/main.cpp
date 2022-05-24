#include <iostream>
#include <cassert>
using namespace std;

/* Section09_06 첨자 연산자 오버로딩 */

class IntList
{
private:
	int m_list[10] = { 0,1,2,3,4,5,6,7,8,9 };
public:
	//void setItem(int index, int value)
	//{
	//	m_list[index] = value;
	//}
	//int getItem(int index)
	//{
	//	return m_list[index];
	//}
	//int* getList()
	//{
	//	return m_list;
	//}
	int& operator [] (const int index)
	{
		assert(index >= 0);
		assert(index < 10);

		return m_list[index];
	}

	// const 버전의 연산자
	const int& operator [] (const int index) const
	{
		assert(index >= 0);
		assert(index < 10);

		return m_list[index];
	}


};

int main()
{
	const IntList my_list;
	//my_list.setItem(3, 1);
	//cout << my_list.getItem(3) << endl;

	//my_list[3] = 10; // l-value여야 하므로 참조로 리턴
	cout << my_list[3] << endl;

	IntList* list = new IntList;
	//list[3] = 10;
	(*list)[3] = 10; // OK
	cout << (*list)[3] << endl;


	return 0;
}