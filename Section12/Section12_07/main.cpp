#include <iostream>
#include <string>
using namespace std;

/* Section12_07 순수 가상함수, 추상 기본클래스, 인터페이스 클래스 */

// 순수 가상함수 : body가 없음
// 추상 기본클래스 : 순수 가상함수가 포함된 클래스
// 인터페이스 클래스 : 순수 가상함수로 이루어진 클래스

class Animal
{
protected:
	string m_name;

public:
	Animal(std::string name) : m_name(name) {}

	string getName() { return m_name; }

	// pure virtual function 순수 가상함수 - 따로 body를 구현놓을수 있지만 실행은 안됨
	// 자식 클래스에서는 반드시 구현해야됨
	// 상속 구조 설계를 도와줌!!
	virtual void speak() const = 0;

};

class Cat : public Animal
{
public:
	Cat(string name) : Animal(name) {}

	void speak() const
	{
		cout << m_name << " Meow " << endl;
	}
};

class Dog : public Animal
{
public:
	Dog(string name) : Animal(name) {}

	void speak() const
	{
		cout << m_name << " Woof " << endl;
	}
};

class Cow : public Animal
{
public:
	Cow(string name) : Animal(name) {}

};

// 인터페이스 클래스, 관습적으로 I를 붙여줌
class IErrorLog
{
public:
	virtual bool reportError(const char* errorMessage) = 0;
	virtual ~IErrorLog() {}
};

class FileErrorLog : public IErrorLog
{
public :
	bool reportError(const char * errorMessage) override
	{
		cout << "writing error to a file" << endl;
		return true;
	}
};

class ConsoleErrorLog : public IErrorLog
{
public:
	bool reportError(const char* errorMessage) override
	{
		cout << "Printing error to a console" << endl;
		return true;
	}
};

void doSomething(IErrorLog& log)
{
	log.reportError("Runtime error");
}


int main()
{
	// 아래는 생성이 안됨. 추상 클래스는 객체를 만들 수 없음
	// Animal ani("HI");

	// 자식 클래스인 Cow에 speak를 만들어 주지 않으면 초기화도 안됨!!
	//Cow cow("hello");

	Dog dog("dog");
	dog.speak();

	cout << endl;

	FileErrorLog file_log;
	ConsoleErrorLog console_log;

	doSomething(file_log);
	doSomething(console_log);


	return 0;
}