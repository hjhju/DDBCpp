#include <iostream>

using namespace std;

/* Section14_02 ����ó���� ���� �ǰ��� */

// void last() throw(int) exception specifier
// void last() throw(...) exception specifier

// throw() �� ()�ȿ� �ƹ��͵� �������� �ƹ��͵� ������ �ʰڴٴ� �ǹ���!
//void last() throw()
void last()
{
	cout << "last " << endl;
	cout << "Throws exception" << endl;

	// last()���� ���� ���� int���̶� catch���� int�ΰ��� ã�Ƽ� ���ư�
	// �� �Ʒ��͵��� ������ ��������!!
	
	//throw - 1;
	throw - 1.0f;

	cout << "End last" << endl;
}

void third()
{
	cout << "Third" << endl;

	last();

	cout << "End Third" << endl;
}

void second()
{
	cout << "Second" << endl;

	try
	{
		third();
	}
	catch (double)
	{
		cerr << "Second caught int exception" << endl;
	}

	cout << "End Second" << endl;

}

void first()
{
	cout << "First" << endl;

	try
	{
		second();
	}
	catch (int)
	{
		cerr << "first caught int exception" << endl;
	}

	cout << "End First" << endl;

}

int main()
{
	cout << "Start" << endl;

	try
	{
		first();
	}
	catch (int)
	{
		cerr << "main caught int exception" << endl;
	}
	catch (...) // catch-all handlers
	{
		cerr << "main caught ellipses exception" << endl;
	}

	return 0;
}