
#ifndef __MULTIPLY_H__
#define __MULTIPLY_H__

//一般来说，inline函数必须要放在头文件里面
//
//
//inline函数内部不要写循环语句
//
inline int multiply(int, int);
//inline
int multiply(int x, int y)
{
	return x * y;
}

//#include "multiply.cc"


#endif
 
