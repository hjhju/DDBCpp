#include "MyArray.h"

// 헤더에서 분리되어 cpp로 와있으면 컴파일러가 어떤 타입으로 구체화해야하는지 몰라서 링킹 에러 뜸

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
// 컴파일러에게 이런 타입으로 빌드하라고 알려주는 행위 - 함수 뿐만이 아니라 클래스에 대해서도 작성가능!
// 
// 컴파일 과정에서 문법체크 및 static한 영역들을 메모리에 할당함
// 각각의 객체마다 멤버변수들은 따로 메모리를 가지지만, 멤버 함수는 따로 가지지 않고 한곳에 저장함
// 그리고 각 객체마다 함수가 정의된 메모리를 공유하여 사용하는 것 - static한 메모리

template class MyArray<char>;
template class MyArray<double>;

//template void MyArray<char>::print();
//template void MyArray<double>::print();
