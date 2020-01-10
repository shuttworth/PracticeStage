 ///
 /// @file    inline.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-02 10:58:03
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//发生时机在预处理时, 简单的进行字符串的替换
#define multi(x,y) ((x)*(y))


//发生时机在编译时
inline
int multiply(int x, int y);//函数的声明
 
int main(void)
{
	int a = 1, b = 2;
	cout << "multiply(a, b): " << multiply(a, b) << endl;
	return 0;
}

//函数的定义
inline
int multiply(int x, int y)
{
	return x * y;
}
