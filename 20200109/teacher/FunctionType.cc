 ///
 /// @file    FunctionType.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-09 15:21:37
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void display()
{
	cout << "display()" << endl;
}

void show()
{
	cout << "show()" << endl;
}

//函数本身就是一种类型
typedef void (*FunctionType)();

typedef int(*FunctionType1)(int);
 
int main(void)
{
	FunctionType f1;
	f1 = display;
	f1();

	f1 = show;
	f1();

	return 0;
}
