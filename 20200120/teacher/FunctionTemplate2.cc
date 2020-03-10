 ///
 /// @file    FunctionTemplate.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-20 09:42:42
 ///
 
#include <iostream>
using std::cout;
using std::endl;



//模板形参列表也可以设置默认值
//
//1. 类型参数
//2. 非类型参数, 整型数据(bool/char/short/int/long/long long)
//	 常量表达式
//


template <class T1, class T2 = int>
T1 func(T1 t1, T2 t2)  //函数形参列表
{
	cout << "sizeof(t2): " << sizeof(t2) << endl;
	return t1 + t2;
}


template <class T, int kMax = 10>
T func(T t1)  //函数形参列表
{
	cout << "sizeof(t1): " << sizeof(t1)<< endl;
	return t1 + kMax ;
}

int main()
{
	float x1 = 1.11;
	double x2 = 2.22;
	int x3 = 10;

	cout << func<float, 20>(x1) << endl;
	cout << func<double, 30>(x2) << endl;

#if 1
	//显式实例化
	cout << func<float, double>(x1, x2) << endl;
	cout << func<float>(x1, x2) << endl;
	cout << func(x1, x3) << endl;
	cout << func(11.1, 2.22) << endl;
#endif


	return 0;
}

