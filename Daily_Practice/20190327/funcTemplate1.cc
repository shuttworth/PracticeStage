#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
		 //实例化
//函数模板 ---> 模板函数    
//		//模板参数推导 ==> 很浪费时间的
//模板相当于是代码生成器
template <typename T>
T add(T x, T y);  //函数模板也可以分成声明与定义

//函数模板与函数模板也是可以重载的
template <typename T>
T add(T x, T y, T z)
{
	cout << "T add(T, T, T)" << endl;
	return x + y + z;
}

//函数模板与普通函数是可以重载的;
//而且普通函数的执行会优先于函数模板
int add(int x, int y)
{
	cout << "int add(int,int)" << endl;
	return x + y;
}

//模板特化**
template <>
const char * add<const char *>(const char * p1, const char * p2)
{
	char * ptmp = new char[strlen(p1) + strlen(p2) + 1](); //需要回收空间  delete [] p;
	strcpy(ptmp, p1);
	strcat(ptmp, p2);
	return ptmp;
}
 
int main(void)
{
	int a1 = 3, a2 = 4, a3 = 5;
	float b1 = 1.1, b2 = 2.2;
	double c1 = 1.2, c2 = 2.3;
	char d1 = 'a';
	const char * p1 = "hello";
	const char * p2 = "world";

	cout << "add(a1, a2) = " << add(a1, a2) << endl;// 隐式实例化
	cout << "add(b1, b2) = " << add<float>(b1, b2) << endl;//显式实例化

	cout << "add(c1, c2) = " << add(c1, c2) << endl;
	cout << "add(d1, 1) = " << add(d1, (char)1) << endl;

	cout << "add(a1, a2, a3) = " << add(a1, a2, a3) << endl;
	const char * p = add(p1, p2);
	cout << "add(p1, p2) = " << p << endl;
	delete [] p;

	return 0;
}

template <typename T>
T add(T x, T y)
{
	cout << "T add(T,T)" << endl;
	return x + y;
}
