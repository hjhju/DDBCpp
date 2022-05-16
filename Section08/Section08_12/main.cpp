#include <iostream>

using namespace std;

/* Section08_14 클래스 안에 포함된 자료형 nested types */

class Fruit
{
	// 한 클래스에서만 사용된다면 enum도 클래스 내부에 선언 가능
public:
	enum class FruitType
	{
		APPLE, BANANA, CHERRY,
	};

private:
	FruitType m_type;

public:
	Fruit(FruitType type) :m_type(type)
	{

	}
	~Fruit()
	{

	}
	FruitType getType() { return m_type; }
};

int main()
{
	// 조금 더 상세하게 표현하고 싶다면 Fruit::FruitType::APPLE 이렇게 적어도 됨

	Fruit apple(Fruit::FruitType::APPLE);

	if (apple.getType() == Fruit::FruitType::APPLE)
	{
		cout << "Apple" << endl;
	}



	return 0;
}