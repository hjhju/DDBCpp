#include <iostream>
#include <string>
#include <cstdarg> // for ellipsis
using namespace std;

/* Section07_15 명령줄 인수 */
/* Section07_16 생략부호 ellipsis (일립시스) */

// ellipsis (일립시스) 사용법
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
	// 프로젝트 -> 속성 -> 디버깅 -> 명령 인수
	for (int count = 0; count < argc; count++)
	{
		//cout << argv[count] << endl;

		std::string argv_single = argv[count];
		if (count == 1)
		{
			int input_number = std::stoi(argv_single); // 문자열을 정수로
			cout << input_number + 1 << endl;
		}
		else
			cout << argv_single << endl;
	}
	
	cout << findAvg(1, 1, 2, 3,"hello",'c') << endl; // 첫번쨰가 1이므로 1만
	cout << findAvg(3,1,2,3) << endl;
	cout << findAvg(5,1,2,3,4,5) << endl;  // 첫번쨰가 5이므로 1~5
	cout << findAvg(10,1,2,3,4,5) << endl;

	
	return 0;
}