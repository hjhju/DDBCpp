#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

/* Section17_02 std::string�� �������� �����ڵ�� ����ȯ  */

template <typename T>
string ToString(T x)
{
	ostringstream osstream;
	osstream << x;
	// ���°��� string���� �ٲټ� ����
	return osstream.str();
}

template <typename T>
bool FromString(const string &str, T &x)
{
	istringstream isstream(str);
	return (isstream >> x) ? true : false;
}

int main()
{
	string my_string("my string");
	cout << my_string << endl;

	string string1(my_string); // my string
	cout << string1 << endl;

	string string2(my_string, 3); // string
	cout << string2 << endl;

	string string3(my_string, 3, 2); // st
	cout << string3 << endl;

	string string4(10, 'A'); // AAAAAAAAAA
	cout << string4 << endl;

	vector<char> vec;
	for (auto e : "Today is a good day.")
		vec.push_back(e);

	for (auto e : vec)
		cout << e ;
	cout << endl;

	string string5(vec.begin(), vec.end());
	cout << string5 << endl;

	string string6(vec.begin(), find(vec.begin(), vec.end(), 'y'));
	cout << string6 << endl;

	// ���ڸ� ���ڿ��� �ٲ�
	string my_str(to_string(4));
	cout << my_str << endl;

	my_str += to_string(1024);
	cout << my_str << endl;

	// ���ڿ��� ���ڷ� �ٲ�
	//int i = stoi(my_str);
	float i = stof(my_str);

	cout << i << endl;

	string my_str2(ToString(3.141592));
	cout << my_str2 << endl;

	double d;

	if (FromString(my_str2, d))
		cout << d << endl;
	else
		cout << "cannot convert" << endl;




	return 0;
}