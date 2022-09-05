#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // exit()
#include <sstream>
using namespace std;

/* Section18_06 �⺻���� ���� �����  */

int main()
{
	//writing
	if (true)
	{
		ofstream ofs("my_first_file.dat"); // ios::app, ios::binary

		if (!ofs)
		{
			cerr << "couldn't open file" << endl;
			exit(1);
		}

		// 1. �ƽ�Ű�� �����ϴ� ��� -> ��û ����!!
		//ofs << "line 1" << endl;
		//ofs << "line 2" << endl;

		
		// 2. binary�� �����ϴ� ���
		const unsigned num_data = 10;
		ofs.write((char*)&num_data, sizeof(num_data));

		for(int i=0;i<num_data;++i)
			ofs.write((char*)&i, sizeof(i));
		

		// 3. ����� ���� ���ڿ� �ϳ��� ��� ����
		/*
		stringstream ss;
		ss << "Line 1" << endl;
		ss << "Line 2" << endl;
		string str = ss.str();

		unsigned str_length = str.size();
		ofs.write((char*)&str_length, sizeof(str_length));
		ofs.write(str.c_str(), str_length);
		*/
	
		// ofs.close(); // not necessary

	}

	// reading
	if (true)
	{
		//ifstream ifs("my_first_file.dat", ios::binary); // ios::app, ios::binary

		ifstream ifs("my_first_file.dat"); // ios::app, ios::binary

		if (!ifs)
		{
			cerr << "cannot open file" << endl;
			exit(1);
		}

		//while (ifs)
		//{
		//	std::string str;
		//	getline(ifs, str);
		//	std::cout << str << endl;
		//}

		unsigned num_data = 0;
		ifs.read((char*)&num_data, sizeof(num_data));// ������ ���� Ȯ��

		for (unsigned i = 0; i < num_data; ++i)
		{
			int num;
			ifs.read((char*)&num, sizeof(num));
			std::cout << num << endl;
		}

		/*
		unsigned str_len = 0;
		ifs.read((char*)&str_len, sizeof(str_len));

		string str;
		str.resize(str_len);
		ifs.read(&str[0], str_len);

		cout << str << endl;
		*/

		//ifs.close() // not necessary
	}

	return 0;
}