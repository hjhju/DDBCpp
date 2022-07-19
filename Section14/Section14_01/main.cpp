#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* Section14_01 예외처리의 기본 */

int findFirstChar(const char* string, char ch)
{
	for (std::size_t index = 0; index < strlen(string); ++index)
	{
		if (string[index] == ch)
			return index;
	}
	return -1; // no match
}

double divide(int x, int y, bool& success)
{
	if (y == 0)
	{
		success = false;
		return 0.0;
	}
	success = false;
	return static_cast<double>(x) / y;
}

int main()
{
	// 아래는 예전부터 사용하던 방식 
	bool success;
	double result = divide(5, 3, success);

	if (!success)
		std::cerr << "An error occurred" << std::endl;
	else
		std::cout << "Result is " << result << std::endl;

	std::ifstream input_file("temp.txt");
	if(!input_file)
		std::cerr << "Cannot open file" << std::endl;


	// 예측할 수 없는 일이 발생할 수 있는 경우
	// try, catch, throw

	double x;
	cin >> x;

	try
	{
		// throw 예외에 해당하는 에러메시지를 던져줌
		// throw에서 std::string를 떼고 보내면 catch가 못받음
		// catch는 형변환을 잘하지 못함
 		// catch에 맞는 형이 존재하지않으면 런타임 에러를 발생시킴!!
		
		//if (x < 0.0) throw std::string("Negative input");
		if (x < 0.0) throw -1.0 ;

		cout << std::sqrt(x) << endl;
	}
	// catch가 에러메시지를 잡아서 대응을 함
	catch (std::string error_message)
	{
		cout << error_message << endl;
	}
	catch (double y)
	{
		cout << y << endl;
	}




	return 0;
}