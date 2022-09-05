#include <iostream>
#include <regex>
using namespace std;

/* Section18_05 정규 표현식 (regular expressions) 소개  */

int main()
{
	//regex re("\\d");  // 숫자 하나를 의미
	//regex re("\\d+");  // 숫자 하나 이상을 의미
	//regex re("[[:digit:]]{3}"); // 숫자 3개를 의미
	
	//regex re("[A-Z]+"); // 대문자 하나 이상을 의미
	//regex re("[A-Z]{1,5}");  // 대문자 최소하나, 최대 다섯개 의미
	regex re("([0-9]{1})([-]?)([0-9]{1,4})"); // [-]? 는 -가 있어도 되고 없어도 되고를 의미


	string str;

	while (true)
	{
		getline(cin, str);

		if (std::regex_match(str, re))
			cout << "match" << endl;
		else
			cout << "no match" << endl;

		// print matches
		{
			auto begin = std::sregex_iterator(str.begin(), str.end(), re);
			auto end = std::sregex_iterator();
			for (auto itr = begin; itr != end; ++itr)
			{
				std::smatch match = *itr;
				cout << match.str() << " ";
			}
			cout << endl;

		}
		cout << endl;


	}


	return 0;
}