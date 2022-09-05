#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // exit()
#include <sstream>
using namespace std;

/* Section18_07 파일의 임의 위치 접근  */

int main()
{
	const string filename = "my_file.txt";

	// make a file
	{
		ofstream ofs(filename);

		for (char i = 'a'; i <= 'z'; ++i)
			ofs << i;
		ofs << endl;
	}

	// read the file
	{
		ifstream ifs("my_file.txt");

		// 파일 처음부터 5바이트 이동후 읽기
		ifs.seekg(5); // ifs.seekg(5, ios::beg);
		cout << (char)ifs.get() << endl;

		// 현재 읽어 들인 위치에서 다시 5바이트 이동후 읽기
		ifs.seekg(5, ios::cur); // ifs.seekg(5, ios::beg);
		cout << (char)ifs.get() << endl;

		// end로 부터 -5바이트 읽기
		ifs.seekg(-5, ios::end);
		cout << (char)ifs.get() << endl;

		ifs.seekg(0, ios::end);
		cout << ifs.tellg() << endl;

		//string str;
		//getline(ifs, str);
		//cout << str << endl;
	}

	{
		fstream iofs(filename);
		iofs.seekg(5);
		cout << (char)iofs.get() << endl;  // read

		iofs.seekg(5);
		iofs.put('A'); //write
	}

	return 0;
}