 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
 
int test0(void)
{
	int number = 10;
	float number2 = 12.12;

	//number = (int)number2;
	number = int(number2);
	number = static_cast<int>(number2);
	cout << "number = " << number << endl;

	int * pint = static_cast<int*>(malloc(sizeof(int)));
	*pint = 1;
	free(pint);
 
	return 0;
}

void test1()
{
	const int number = 1;
	//int * p = &number;//error
	//*p = 10;
	int * p = const_cast<int*>(&number);
	*p = 10;
	cout << "number = " << number << endl;
	cout << "*p = " << *p << endl;
	cout << "&number = " << &number << endl;
	cout << "p = " << p << endl;
}

void test2(int * p)
{

}

int main()
{
	test1();
	const int number = 1;
	test2(const_cast<int*>(&number)); //用const_cast来去除const限定
}
