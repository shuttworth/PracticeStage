 ///
 /// @file    FunctionTemplate.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-20 09:42:42
 ///

#include <string.h>

#include <iostream>
using std::cout;
using std::endl;


//函数声明有多次，但定义只能有1次

//模板可以理解成  代码生成器

//		  实例化
// 函数模板 ==>  模板函数
//		 模板参数推导

template <class T>    // 尖括号代表的就是模板形参列表
T add(T t1, T t2); //函数模板的声明


template <class T>
T add(T t1, T t2, T t3)
{
	return t1 + t2 + t3;
}


#if 0
template <class T1, class T2>
T1 add(T1 t1, T2 t2)
{
	return t1 + t2;
}
#endif

//函数模板与函数模板之间也可以重载

//普通函数与函数模板形成重载, 普通函数要优先调用

#if 0
int add(int t1, int t2)
{
	cout << "int add(int,int) " << endl;
	return t1 + t2;
}
#endif 

//模板的特化(Specialization)版本
//它不能单独存在，必须先有通用形式，才有特化版本的形式
//可以有多个
template <>
const char * add<const char *>(const char * p1, const char * p2)
{
	char * tmp = new char[strlen(p1) + strlen(p2) + 1]();
	strcpy(tmp, p1);
	strcat(tmp, p2);
	return tmp;
}


int main(void)
{
	int x1 = 1, x2 = 2;
	float x3 = 1.11, x4 = 2.22;
	double x5 = 11.11, x6 = 12.12, x9 = 9.99;
	char x7 = 'a', x8 = 1;
	const char * p1 = "hello", * p2 = "world";

	//cout << "add(x1, x3): " << add(x1, x3) << endl;//error add(int,float)

#if 0
	cout << "add(x1, x2): " << add(x1, x2) << endl // 隐式实例化
		 << "add(x3, x4): " << add<float>(x3, x4) << endl //显式实例化
		 << "add(x5, x6): " << add(x5, x6) << endl
		 << "add(x7, x8): " << add(x7, x8) << endl;

	cout << "add(x5, x6, x9): " << add(x5, x6, x9) << endl;
#endif

	cout << "add(p1, p2): " << add(p1, p2) << endl;
	return 0;
}

#if 1
template <class T>    // 尖括号代表的就是模板形参列表
T add(T t1, T t2)
{
	cout << "T add(T,T) " << endl;
	return t1 + t2;
}
#endif
