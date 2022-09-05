#include <iostream>
#include <regex>
using namespace std;

/* Section18_05 ���� ǥ���� (regular expressions) �Ұ�  */

int main()
{
	//regex re("\\d");  // ���� �ϳ��� �ǹ�
	//regex re("\\d+");  // ���� �ϳ� �̻��� �ǹ�
	//regex re("[[:digit:]]{3}"); // ���� 3���� �ǹ�
	
	//regex re("[A-Z]+"); // �빮�� �ϳ� �̻��� �ǹ�
	//regex re("[A-Z]{1,5}");  // �빮�� �ּ��ϳ�, �ִ� �ټ��� �ǹ�
	regex re("([0-9]{1})([-]?)([0-9]{1,4})"); // [-]? �� -�� �־ �ǰ� ��� �ǰ� �ǹ�


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