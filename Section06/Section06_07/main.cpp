#include <iostream>

using namespace std;

/* Section06_10 c��� ��Ÿ���� ���ڿ� �ɺ��� ��� */

const char *getName()
{
	return "Jack jack";
}

int main()
{
	// ������ ������ ���ͷ��� ���� ���� ����
	// char* name = "Jack jack"; 
	// const�� �ٿ��߸� ��ȣ�� ���ó�� ����� �� ����
	const char *name = "Jack jack";
	const char *name2 = getName();

	cout << (uintptr_t)name << endl; // ���� ���ڿ��̸� ���� �ּҰ� ���
	cout << (uintptr_t)name2 << endl;


	int int_arr[5] = { 1, 2, 3, 4, 5 };
	char char_Arr[] = "hello world";
	const char* name3 = "kim jack";

	cout << int_arr << endl; //�ּҰ� ���
	cout << char_Arr << endl; // ���ڿ��� ���
	cout << name3 << endl; // ���ڿ��� ���

	// cout�� ���ڿ��� Ư���ϰ� ���


	return 0;
}