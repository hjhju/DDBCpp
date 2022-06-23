#include <iostream>

using namespace std;

/* Section12_03 override, final, ���� ��ȯ�� */

class A
{
public:
	// ��ӵ� �������̵��� �Լ��鿡�� virtual Ű���带 �߰��ϴ� ���� ����!!
	virtual void print(int x) { cout << "A" << endl; }

	void print() { cout << "A" << endl; }

	virtual A* getThis() { return this; }

};

class B : public A
{
public:
	// �Ķ���Ͱ� Ÿ���� �������̵��� �ȵ�
	//void print(short x) { cout << "B" << endl; }
	
	// �ڵ� �� override Ű���带 �ۼ��ϴ°��� �Ǽ� Ȯ���� �پ��
	void print(int x) override { cout << "B" << endl; }

	virtual B* getThis() { return this; }

	void print() { cout << "B" << endl; }


};

class C : public B
{
public:
	// final�� �ڽ� Ŭ������ �������̵��� ������
	void print(int x) final { cout << "C" << endl; }

	virtual C* getThis() { return this; }

	void print() { cout << "C" << endl; }


};

class D : public C
{
public:
	// C���� final�� �޷������Ƿ� ���� ��
	//void print(int x) { cout << "D" << endl; }
};


int main()
{
	A a;
	B b;

	A& ref = b;
	ref.print(5); 
	

	b.getThis()->print();

	// B�� �����͸� ���������� A�� �����ͷ� �ٲ㼭 print�� �����Ŵ
	// print()�� �����Լ��� �ƴ� �Ϲ��Լ� �̹Ƿ� A�� print�� ����Ǵ� ��
	ref.getThis()->print(); //A

	// typeid�� ���ڰ� ������ Ÿ���� ��쿡�� �����ϰ�
	// �׷��� ������ ������ Ÿ�Ը� ��ȯ��
	cout << typeid(b.getThis()).name() << endl;
	cout << typeid(ref.getThis()).name() << endl; // Class A


	return 0;
}