#include <iostream>
#include <vector>

using namespace std;

/* Section04_09 : �ڷ������� ���� �ٿ��ֱ� */


int main()
{
	// �����̶�� �����ϸ� ��

	typedef double distance_t; //_t�� Ÿ���� �ǹ�

	std::int8_t i(97); // �����ʺ񺯼�

	double		my_distance;
	distance_t	home2work;
	distance_t	home2school;
	
	// home2~ �κ����� float�� �Ǿ���Ѵٸ� typedef float distance_t;���� �����ϸ� ��


	// ������ �ڷ����� ������ ���� ǥ�� ���� 
	//1)
	//typedef vector<pair<string, int>> pairlist_t;
	//2) using���ε� ǥ�� ����
	using pairlist_t = vector<pair<string, int>>;

	pairlist_t pairlist1;
	pairlist_t pairlist2;

	
	return 0;
}