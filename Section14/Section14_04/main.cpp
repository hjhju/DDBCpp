#include <iostream>
#include <exception>
#include <string>
using namespace std;

/* Section14_04 exception 소개 */

class CustomException : public std::exception
{
public:
	// noexcept는 c++11이상에서 사용해야됨, 적어도 이 안에서는 예외를 던지지 않겠다는 의미
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
		// 자식 클래스의 이름을 알려줌
		std::cout << typeid(e).name() << std::endl;
		std::cerr << e.what() << std::endl;
	}

	return 0;
}