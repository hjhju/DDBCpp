#include <iostream>

using namespace std;

/* Section14_03 예외 클래스와 상속 */

// 사용자 정의 예외 클래스
class Exception
{
public:
	void report()
	{
		cerr << "Exception report" << endl;
	}
};

class ArrayException : public Exception
{
public:
	void report()
	{
		cerr << "Array exception report" << endl;
	}
};

class MyArray
{
private:
	int m_data[5];
public:
	int& operator [] (const int& index)
	{
		// if (index < 0 || index >= 5) throw - 1;
		// 
		// 클래스를 throw로 던짐
		//if (index < 0 || index >= 5) throw Exception();

		// exception은 부모것이 출력됨 -> 해결 방안 : doSomthing에서 throw 위치 바꿔주면 됨
		if (index < 0 || index >= 5) throw ArrayException();

		return m_data[index];
	}
};

void doSomething()
{
	MyArray my_array;

	try
	{
		my_array[100];
	}
	catch (const int &x)
	{
		cerr << "Exception " << x << endl;
	}
	// ArrayException이 Exception보다 위에 있으면 먼저 잡힘
	catch (ArrayException& e)
	{
		cout << "doSomething()" << endl;
		e.report();
		// main의 throw를 처리하기위해 받은 것을 다시 던져줌 - rethrow 행위
		throw e;
		
		//throw;
	}
	catch (Exception & e)
	{
		cout << "doSomething()" << endl;
		e.report();
	}

}

int main()
{
	try
	{
		doSomething();
	}
	// 일반적으로 안에서 처리되면 아래의 catch는 무시됨
	catch (ArrayException& e)
	{
		cout << "main()" << endl;
		e.report();
	}

	return 0;
}