#include <iostream>
#include <string>
using namespace std;

/* Section12_01 �������� �⺻ ���� */

// �ڽ� Ŭ������ ��ü�� �θ� Ŭ������ �����͸� ����Ѵٸ�? - ������


class Animal
{
protected:
	string m_name;

public:
	Animal(std::string name) : m_name(name) {}

	string getName() { return m_name; }
	
	// virtual !! - �����Լ�
	virtual void speak() const
	{
		cout << m_name << " ??? " << endl;
	}
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

int main()
{
	Animal animal("my animal");
	Cat cat("my cat");
	Dog dog("my dog");

	animal.speak();
	cat.speak();
	dog.speak();

	cout << endl;

	Animal* ptr_animal1 = &cat;
	Animal* ptr_animal2 = &dog;

	ptr_animal1->speak(); 
	ptr_animal2->speak();

	Cat cats[] = { Cat("cat1"), Cat("cat2"), Cat("cat3") };
	Dog dogs[] = { Dog("dog1"), Dog("dog2") };

	cout << endl;

	for (int i = 0; i < 3; i++)
		cats[i].speak();

	for (int i = 0; i < 2; i++)
		dogs[i].speak();

	cout << endl;

	// ���� �θ�� ���� ��ӹ޾ұ� ������ �̷��� ĳ���� ����
	Animal* my_animals[] = { &cats[0], &cats[1], &cats[2], &dogs[0], &dogs[1] }; 

	for (int i = 0; i < 5; i++)
		my_animals[i]->speak();


	return 0;
}