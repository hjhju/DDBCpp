#include <iostream>
#include <memory>
#include <string>

using namespace std;

/* Section15_07 순환 의존성 문제와 std::weak_ptr */

class Person
{
	std::string m_name;
	// shared_ptr은 소유권이 순환되어 꼬여서 서로 삭제가 안됨!!
	//std::shared_ptr<Person> m_partner;
	std::weak_ptr<Person> m_partner;


public:
	Person(const std::string& name) : m_name(name)
	{
		std::cout << m_name << " created\n";
	}

	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2)
	{
		if (!p1 || !p2)
			return false;

		p1->m_partner = p2;
		p2->m_partner = p1;

		std::cout << p1->m_name << " is partnered with " << p2->m_name << "\n";
		
		return true;
	}

	const std::shared_ptr<Person> getPartner() const
	{
		// weak포인터는 직접 사용할수 없고 lock()을 이용하여 shared_ptr로 바꿔서 리턴함
		return m_partner.lock();
	}

	const std::string& getName() const
	{
		return m_name;
	}

};

int main()
{
	auto lucy = std::make_shared<Person>("Lucy");
	auto ricky = std::make_shared<Person>("Ricky");

	partnerUp(lucy, ricky);

	std::cout << lucy->getPartner()->getName() << std::endl;


	return 0;
}