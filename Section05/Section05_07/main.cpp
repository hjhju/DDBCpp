#include <iostream>
#include <cstdlib> //std::radn(), std::srand()
#include <ctime> // std::time()
#include <random>
using namespace std;

/* Section05_09 ���� ����� */

// ���� ����� ����
unsigned int PRNG() //Pseudo Random Number Generator
{
	// ��� �ٲ�� ���� ��������� static ���
	static unsigned int seed = 5523; // seed number

	seed = 8353729 * seed + 2396403;

	return seed % 32768;
}

// ������� �� ���� -> static �Ǵ� ���� ��� ���� ����ص� ��
// const double fraction = 1.0 / (RAND_MAX);

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (RAND_MAX+1.0);

	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

int main()
{
	// seed�� ������ ���� ����ϸ� ��� ���� ���� ����
	// ������� �ʿ��Ҷ��� �������Ѽ� ����ϴ� ���� ����
	// std::srand(5323); // seed ���� 
	std::srand(static_cast<unsigned int>(std::time(0))); //�ð��� �귯���� ���� Ȱ���ؼ� seed ����

	for (int count = 1; count <= 100; ++count)
	{
		//cout << std::rand() % 5 + 2 << '\t';
		cout << getRandomNumber(2,8) << '\t';
		if (count % 5 == 0)
			cout << endl;
	}

	/* c++11���� ���� random ���̺귯��*/

	std::random_device rd; // seed�� ���� ������ ���� ����̽� ���� (time ������ ����)
	// mt19937�� 32bit random number ��������
	// create a mesenne twister 
	std::mt19937 mersenne(rd()); 

	std::uniform_int_distribution<> dice(1, 6); // 1~6���� ���� Ȯ���� ����

	for (int count = 1; count <= 20; ++count)
	{
		cout << dice(mersenne) << endl;
	}



	return 0;
}