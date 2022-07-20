#include <iostream>

using namespace std;

/* Section15_02 ������ �� ���� (r-value referecne) */

void doSomething(int &lef)
{
	cout << "L-value ref" << endl;
}

void doSomething(int&& ref)
{
	cout << "R-value ref" << endl;
}

int getResult()
{
	return 100 * 100;
}

int main()
{
	int x = 5;
	int y = getResult();
	// const�� ���Ŀ� �� ���� �Ұ�
	const int cx = 6;
	const int cy = getResult();

	// �ּ�ó�� �Ȱ��� ������ �ȵǴ� �͵�
	
	/* L-value references (L-value�� ���� ������ ���� �� ����!!) */
	// L-value�� �޸𸮸� ����

	int& lr1 = x; // modifiable l-values
	// int &lr2 = cx; // non-modifiable l-values
	// int &lr3 = 5; // R-values�� ���� �� ����

	const int& lr4 = x; // modifiable l-values
	const int& lr5 = cx; // non-modifiable l-values
	const int& lr6 = 5; // R-values


	/* R-value references (R-value�� ���� ������ ���� �� ����!!) */
	// R-value�� �޸𸮸� ������ ���� ex) ���ͷ�
	
	//int &&rr1 = x; // modifiable l-values
	//int &&rr2 = cx; // non-modifiable l-values
	int &&rr3 = 5; // R-values

	// 5��� ���� rr3�� �����ϰ� rr3�� ���� �ٲܼ� ����
	cout << rr3 << endl;
	rr3 = 10;
	cout << rr3 << endl;

	//const int&& rr4 = x; // modifiable l-values
	//const int&& rr5 = cx; // non-modifiable l-values
	const int&& rr6 = 5; // R-values

	// ����� ���� �ӽ÷� �����ϴ� �뵵
	int&& rrr = getResult();


	// L/R value references (doSomething �����ε�)
	doSomething(x);  // L-value
	//doSomething(cx);
	doSomething(5);  // R-value
	doSomething(getResult()); // R-value



	return 0;
}