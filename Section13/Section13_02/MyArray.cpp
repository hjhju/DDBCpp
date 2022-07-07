#include "MyArray.h"

// ������� �и��Ǿ� cpp�� �������� �����Ϸ��� � Ÿ������ ��üȭ�ؾ��ϴ��� ���� ��ŷ ���� ��

template <typename T>
void MyArray<T>::print()
{
	for (int i = 0; i < m_length; ++i)
	{
		std::cout << m_data[i] << " ";
	}
	std::cout << std::endl;
}

// explicit instantiation
// �����Ϸ����� �̷� Ÿ������ �����϶�� �˷��ִ� ���� - �Լ� �Ӹ��� �ƴ϶� Ŭ������ ���ؼ��� �ۼ�����!
// 
// ������ �������� ����üũ �� static�� �������� �޸𸮿� �Ҵ���
// ������ ��ü���� ����������� ���� �޸𸮸� ��������, ��� �Լ��� ���� ������ �ʰ� �Ѱ��� ������
// �׸��� �� ��ü���� �Լ��� ���ǵ� �޸𸮸� �����Ͽ� ����ϴ� �� - static�� �޸�

template class MyArray<char>;
template class MyArray<double>;

//template void MyArray<char>::print();
//template void MyArray<double>::print();
