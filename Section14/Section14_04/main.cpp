#include <iostream>
#include <exception>
#include <string>
using namespace std;

/* Section14_04 exception �Ұ� */

class CustomException : public std::exception
{
public:
	// noexcept�� c++11�̻󿡼� ����ؾߵ�, ��� �� �ȿ����� ���ܸ� ������ �ʰڴٴ� �ǹ�
	const char* what() const noexcept override
	{
		return "Custom exception";
	}
};

int main()
{
	try
	{
		/*std::string s;
		s.resize(-1);*/

		// throw std::runtime_error("Bad thing happend");

		throw CustomException();

		
	}
	/*
	catch (std::length_error& e)
	{
		std::cout << "length_error" << std::endl;
		std::cerr << e.what() << std::endl;
	}
	*/
	catch(std::exception & e)
	{
		// �ڽ� Ŭ������ �̸��� �˷���
		std::cout << typeid(e).name() << std::endl;
		std::cerr << e.what() << std::endl;
	}

	return 0;
}