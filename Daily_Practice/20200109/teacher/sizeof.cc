 ///
 /// @file    sizeof.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-09 11:27:59
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	int number = 1;
	//sizeof 是一个运算符/操作符, 并不是函数
	printf("sizeof number: %d\n", sizeof number);//编译时就能得到大小
	printf("sizeof int: %d\n", sizeof(int));//error编译时就能得到大小

	return 0;
}
