 ///
 /// @file    Empty.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-04 09:34:10
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Empty
{

};//对象被销毁时，会调用析构函数
 
int main(void)
{
	Empty e1;//默认构造函数

	Empty e2 = e1;//拷贝构造函数

	e2 = e1;//调用赋值运算符函数
		
	cout << "sizeof(Empty) = " << sizeof(Empty) << endl;
	cout << "&e1: " << &e1 << endl
		 << "&e2: " << &e2 << endl;
 
}
