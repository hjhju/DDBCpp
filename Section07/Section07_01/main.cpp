#include <iostream>
#include <vector>
using namespace std;

/* Section07_01 매개변수와 실인자의 구분 */
/* Section07_02 값에 의한 전달 (call by value) */
/* Section07_03 참조에 의한 전달 (call by reference) */


//void printArr(int (&arr)[4]) // element의 개수가 반드시 들어가야됨
void printArr(const vector<int>& arr) // 이게 훨씬 편함
{
	cout << arr.size() << " "<<&arr<<endl;
}

// 참조 값이 인자인데 foo2(3)이면 컴파일 에러가 발생 -> 3은 값이고 주소를 전달하지 않기때문 -> &를 때거나 const 붙이면 해결됨
// 안변하는 값이면 const는 꼭 붙이는것이 좋다
void foo2(const int& x) 
{
	cout << x << endl;
}

// ((int*) &ptr)이라고 생각하면 됨
void foo3(int *&ptr)
{
	cout << ptr << " " << &ptr << endl;
	ptr++;
}

void getSinCos(const double &degrees, double& sin_out, double& cos_out)
{
	static const double pi = 3.141592 / 180.0;
	const double radians = degrees * pi ;
	sin_out = std::sin(radians);
	cos_out = std::cos(radians);
}

void addOne(int &y)
{
	cout << "In func " << y << " " << &y << endl;
	y = y + 1;
}


void doSomething(int y)
{
	cout << "In func " << y << " " << &y << endl;
}


int foo(int x, int y)
{
	return x + y;
} // x and y are destroyed here

int main()
{
	int x = 1, y = 2;

	foo(6, 7); // 6, 7 : arguments (actual parameters, 실인자
	foo(x, y + 1); 

	// 값만 전달됨, 함수와 main에서의 주소값이 다름
	doSomething(5);
	doSomething(x);
	cout << "In main " << x << " " << &x << endl;
	doSomething(x+1);
	cout<< endl;

	// 함수와 메인에서의 주소값이 같음, 값이 영향받음
	x = 5;
	cout << "In main " << x << " " << &x << endl;
	addOne(x);
	cout << "In main " << x << " " << &x << endl;
	cout << endl;

	double sin(0.0);
	double cos(0.0);

	getSinCos(30.0, sin, cos);
	cout << sin << " " << cos << endl;
	cout << endl;

	foo2(6);

	int* ptr = &x;
	cout << ptr << " " << &ptr << endl;
	foo3(ptr);
	cout << ptr << " " << &ptr << endl;
	cout << endl;

	int arr[]{ 1,2,3,4 };
	vector<int> arr2{ 1,2,3,4 };
	cout << arr2.size() << " " << &arr2 << endl;
	printArr(arr2);

	return 0;
}