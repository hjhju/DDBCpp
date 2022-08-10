#include <iostream>
#include <string>
#include <cstddef>
#include <locale>
using namespace std;

/* Section17_01 std::string과 std::wstring  */

int main()
{
	// c-style string example
	{
		char *strHello = new char[7];
		strcpy_s(strHello, sizeof(char)*7, "hello!");
		cout<<strHello<<endl;
	}
	
	// basic_string<>, string, wstring
	string string;
	wstring wstring;

	wchar_t ws; // wide-character/unicode

	// wstring example
	// https://stackoverflow.com/questions/33404685/c-code-to-cout-international-characters-using-visual-studio-2015
	{

		const std::wstring texts[] = {
		   L"안녕",
		   L"Ñá", //Spanish
		   L"forêt intérêt", //French
		   L"Gesäß", //German
		   L"取消波蘇日奇諾", //Chinese
		   L"日本人のビット", //Japanese
		   L"немного русский", //Russian
		   L"ένα κομμάτι της ελληνικής", // Greek
		   L"ਯੂਨਾਨੀ ਦੀ ਇੱਕ ਬਿੱਟ", // Punjabi (wtf?). xD
		   L"کمی از ایران ", // Persian (I know it, from 300 movie)
		   L"కానీ ఈ ఏమి నరకం ఉంది?", //Telugu (telu-what?)
		   L"Но какво, по дяволите, е това?" //Bulgarian
		};

		std::locale::global(std::locale(""));
		wcout.imbue(std::locale());

		for (size_t i = 0; i < 12; ++i)
			wcout << texts[i] << endl;

	}

	return 0;
}