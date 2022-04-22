#include <iostream>
#include <cstring>

using namespace std;

/* Section06_06 c언어 스타일의 배열 문자열 */

int main()
{
	char myString[] = "string";

	for (int i = 0; i < 7; i++)
	{
		cout << (int)myString[i] << endl; //아스키코드 확인
	}

	/*
	char myString2[255];
	cin >> myString2;
	myString2[4] = '\0';
	cout << myString2 << endl; //문자열의 '\0'이 나오기 전까지만 출력
	*/

	/*
	char myString3[255];
	cin.getline(myString3, 255);
	int idx = 0;
	while (true)
	{
		if (myString3[idx] == '\0') break;
		cout << myString3[idx] << " " << (int)myString3[idx] << endl;
		idx++;
	}
	*/

	char source[] = "Copy this!";
	char dest[50];
	strcpy_s(dest, 50, source);

	cout << source << endl;
	cout << dest << endl;

	if (strcmp(source, dest) == 0) // strcmp는 같으면 0을 반환
	{
		cout << "same" << endl;
	}
	


	return 0;
}