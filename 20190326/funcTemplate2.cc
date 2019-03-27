 ///
 /// @file    funcTemplate2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-11-05 11:47:24
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//模板参数有两类:
//1. 类型参数
//2. 非类型参数, 整型常量
//
//函数模板参数可以设置默认值(c++11)
//整型数据类型有: bool, char, short, int, long, long long
template <typename T,  char kNumber = 1>
T multiply(T x)
{
	return x * kNumber;
}
 
int main(void)
{
	int a1 = 10;
	cout << "multiply(a1) = " << multiply<int, 10>(a1) << endl;
	cout << "multiply(a1) = " << multiply(a1) << endl;
	return 0;
}
