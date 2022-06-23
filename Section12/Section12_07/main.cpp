#include <iostream>
#include <string>
using namespace std;

/* Section12_07 ���� �����Լ�, �߻� �⺻Ŭ����, �������̽� Ŭ���� */

// ���� �����Լ� : body�� ����
// �߻� �⺻Ŭ���� : ���� �����Լ��� ���Ե� Ŭ����
// �������̽� Ŭ���� : ���� �����Լ��� �̷���� Ŭ����

class Animal
{
protected:
	string m_name;

public:
	Animal(std::string name) : m_name(name) {}

	string getName() { return m_name; }

	// pure virtual function ���� �����Լ� - ���� body�� ���������� ������ ������ �ȵ�
	// �ڽ� Ŭ���������� �ݵ�� �����ؾߵ�
	// ��� ���� ���踦 ������!!
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

// �������̽� Ŭ����, ���������� I�� �ٿ���
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
	// �Ʒ��� ������ �ȵ�. �߻� Ŭ������ ��ü�� ���� �� ����
	// Animal ani("HI");

	// �ڽ� Ŭ������ Cow�� speak�� ����� ���� ������ �ʱ�ȭ�� �ȵ�!!
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