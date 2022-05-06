#include <iostream>
#include <vector>
using namespace std;

/* Section07_10 ���ð� �� */
/* Section07_11 std::vector�� ����ó�� ����ϱ� */

// Heap
// Stack : ����, ����� ����
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
	ptr = new int[1000000];  // ���� �Ҵ� heap

	delete[] ptr;
	ptr = nullptr;

	std::vector<int> v{ 1,2,3 };
	// size : �Ҵ�Ȱ� �� ����ϴ� ����
	// capacity : �޸�
	
	v.reserve(1024); // �̸� �޸𸮸� �����ϴ°�

	 // ũ�Ⱑ ���� �������� resize�Ѵٸ� ���������� ó��
	v.resize(10);
	for (auto& e : v)
		cout << e << " ";
	cout << endl;
	cout << v.size() << " "<<v.capacity()<< endl; // 10, 10

	// ũ�Ⱑ ���� �������� resize�Ѵٸ� ���������� ó��
	v.resize(2);
	for (auto& e : v)
		cout << e << " ";
	cout << endl;
	cout << v.size() << " " << v.capacity() << endl; // 2, 10

	//cout << v.at(2) << endl; //���� ��
	int* ptr2 = v.data();
	cout << ptr2[2] << endl; // ������ ��� ����
	cout << endl;

	// vector�� stackó�� ���
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