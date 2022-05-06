#include <iostream>
#include <vector>
using namespace std;

/* Section07_10 스택과 힙 */
/* Section07_11 std::vector를 스택처럼 사용하기 */

// Heap
// Stack : 빠름, 사이즈가 작음
// Data
//   - initialized data segment
//   - initialized global and static variables
// Block started by symbol
//   - uninitialized data segment
//   - zero-initialized global and static variables
// Code


int g_i = 0; 

int second(int x) // stack frame
{
	return 2 * x;
}

int first(int x) // stack frame
{
	int y = 3;
	return second(x+y);
}

void printStack(const vector<int> &stack)
{
	for (auto& e : stack)
		cout << e << " ";
	cout << endl;
}

// stack frame
int main()
{
	int a = 1, b; // stack frame
	b = first(a); // stack frame
	cout << b << endl;  // stack frame

	// int array[1000000]; // stack overflow

	int* ptr = nullptr; // stack frame
	ptr = new int[1000000];  // 동적 할당 heap

	delete[] ptr;
	ptr = nullptr;

	std::vector<int> v{ 1,2,3 };
	// size : 할당된것 중 사용하는 개수
	// capacity : 메모리
	
	v.reserve(1024); // 미리 메모리를 예약하는것

	 // 크기가 작은 방향으로 resize한다면 눈속임으로 처리
	v.resize(10);
	for (auto& e : v)
		cout << e << " ";
	cout << endl;
	cout << v.size() << " "<<v.capacity()<< endl; // 10, 10

	// 크기가 작은 방향으로 resize한다면 눈속임으로 처리
	v.resize(2);
	for (auto& e : v)
		cout << e << " ";
	cout << endl;
	cout << v.size() << " " << v.capacity() << endl; // 2, 10

	//cout << v.at(2) << endl; //오류 뜸
	int* ptr2 = v.data();
	cout << ptr2[2] << endl; // 강제로 출력 가능
	cout << endl;

	// vector를 stack처럼 사용
	vector<int> stack;
	stack.push_back(3);
	printStack(stack);

	stack.push_back(5);
	printStack(stack);

	stack.push_back(7);
	printStack(stack);

	stack.push_back(9);
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);




	return 0;
}