#include <iostream>

using namespace std;

/* Section08_14 Ŭ���� �ȿ� ���Ե� �ڷ��� nested types */

class Fruit
{
	// �� Ŭ���������� ���ȴٸ� enum�� Ŭ���� ���ο� ���� ����
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
	// ���� �� ���ϰ� ǥ���ϰ� �ʹٸ� Fruit::FruitType::APPLE �̷��� ��� ��

	Fruit apple(Fruit::FruitType::APPLE);

	if (apple.getType() == Fruit::FruitType::APPLE)
	{
		cout << "Apple" << endl;
	}



	return 0;
}