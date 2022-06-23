#include <iostream>

using namespace std;

/* Section12_03 override, final, 공변 반환값 */

class A
{
public:
	// 상속된 오버라이딩된 함수들에도 virtual 키워드를 추가하는 것이 좋음!!
	virtual void print(int x) { cout << "A" << endl; }

	void print() { cout << "A" << endl; }

	virtual A* getThis() { return this; }

};

class B : public A
{
public:
	// 파라미터가 타르면 오버라이딩이 안됨
	//void print(short x) { cout << "B" << endl; }
	
	// 코딩 시 override 키워드를 작성하는것이 실수 확률이 줄어듦
	void print(int x) override { cout << "B" << endl; }

	virtual B* getThis() { return this; }

	void print() { cout << "B" << endl; }


};

class C : public B
{
public:
	// final은 자식 클래스의 오버라이딩을 막아줌
	void print(int x) final { cout << "C" << endl; }

	virtual C* getThis() { return this; }

	void print() { cout << "C" << endl; }


};

class D : public C
{
public:
	// C에서 final이 달려있으므로 오류 뜸
	//void print(int x) { cout << "D" << endl; }
};


int main()
{
	A a;
	B b;

	A& ref = b;
	ref.print(5); 
	

	b.getThis()->print();

	// B의 포인터를 내부적으로 A의 포인터로 바꿔서 print를 실행시킴
	// print()가 가상함수가 아닌 일반함수 이므로 A의 print가 실행되는 것
	ref.getThis()->print(); //A

	// typeid는 인자가 다형성 타입일 경우에만 실행하고
	// 그렇지 않으면 정적인 타입만 반환함
	cout << typeid(b.getThis()).name() << endl;
	cout << typeid(ref.getThis()).name() << endl; // Class A


	return 0;
}