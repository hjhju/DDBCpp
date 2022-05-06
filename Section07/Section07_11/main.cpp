#include <iostream>
#include <string>
#include <cstdarg> // for ellipsis
using namespace std;

/* Section07_15 ����� �μ� */
/* Section07_16 ������ȣ ellipsis (�ϸ��ý�) */

// ellipsis (�ϸ��ý�) ����
double findAvg(int count, ...)
{
	double sum = 0;
	va_list list;
	va_start(list, count);

	for (int arg = 0; arg < count; arg++)
		sum += va_arg(list, int);

	va_end(list);

	return sum / count;
}

int main(int argc, char *argv[])
{
	// ������Ʈ -> �Ӽ� -> ����� -> ��� �μ�
	for (int count = 0; count < argc; count++)
	{
		//cout << argv[count] << endl;

		std::string argv_single = argv[count];
		if (count == 1)
		{
			int input_number = std::stoi(argv_single); // ���ڿ��� ������
			cout << input_number + 1 << endl;
		}
		else
			cout << argv_single << endl;
	}
	
	cout << findAvg(1, 1, 2, 3,"hello",'c') << endl; // ù������ 1�̹Ƿ� 1��
	cout << findAvg(3,1,2,3) << endl;
	cout << findAvg(5,1,2,3,4,5) << endl;  // ù������ 5�̹Ƿ� 1~5
	cout << findAvg(10,1,2,3,4,5) << endl;

	
	return 0;
}