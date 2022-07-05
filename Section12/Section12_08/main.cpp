#include <iostream>

using namespace std;

/* Section12_08 가상 기본 클래스와 다이아몬드 상속 문제 */

class PoweredDevice
{
public:
	int m_i;

	PoweredDevice(int power)
	{
		cout << "PoweredDevice : " << power << endl;
	}
};

class Scanner : virtual public PoweredDevice
{
public:
	Scanner(int scanner, int power)
		: PoweredDevice(power)
	{
		cout << "Scanner : " << scanner << endl;
	}
};

class Printer : virtual public PoweredDevice
{
public:
	Printer(int printer, int power)
		: PoweredDevice(power)
	{
		cout << "Printer : " << printer << endl;
	}
};

class Copier : public Scanner, public Printer
{
public:
	Copier(int scanner, int printer, int power)
		: Scanner(scanner, power), Printer(printer, power), PoweredDevice(power)
	{

	}
};

int main()
{
	Copier cop(1, 2, 3);

	// virtual로 상속받고 Copier의 생성자에 PoweredDevice(power)가 추가되면 
	// PoweredDevice는 한번만 생성되고 아래의 주소값은 동일하게 출력됨

	cout << &cop.Scanner::PoweredDevice::m_i << endl;
	cout << &cop.Printer::PoweredDevice::m_i << endl;



	return 0;
}