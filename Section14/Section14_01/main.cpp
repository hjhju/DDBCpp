#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* Section14_01 ����ó���� �⺻ */

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
	// �Ʒ��� �������� ����ϴ� ��� 
	bool success;
	double result = divide(5, 3, success);

	if (!success)
		std::cerr << "An error occurred" << std::endl;
	else
		std::cout << "Result is " << result << std::endl;

	std::ifstream input_file("temp.txt");
	if(!input_file)
		std::cerr << "Cannot open file" << std::endl;


	// ������ �� ���� ���� �߻��� �� �ִ� ���
	// try, catch, throw

	double x;
	cin >> x;

	try
	{
		// throw ���ܿ� �ش��ϴ� �����޽����� ������
		// throw���� std::string�� ���� ������ catch�� ������
		// catch�� ����ȯ�� ������ ����
 		// catch�� �´� ���� �������������� ��Ÿ�� ������ �߻���Ŵ!!
		
		//if (x < 0.0) throw std::string("Negative input");
		if (x < 0.0) throw -1.0 ;

		cout << std::sqrt(x) << endl;
	}
	// catch�� �����޽����� ��Ƽ� ������ ��
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