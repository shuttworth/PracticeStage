 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-03 09:58:24
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	//当没有定义默认构造函数时，编译器会主动提供一个
	//
	//构造函数的作用就是用来初始化数据成员
	//
	//Point(){}
#if 1
	Point()
	{
		_ix = 0;//赋值语句
		_iy = 0;
		cout << "Point()" << endl;
	}

	//一旦定义了一个有参构造函数时，编译器就不会再主动提供
	//默认构造函数
	Point(int x, int y)
	{
		_ix = x;
		_iy = y;
		cout << "Point(int,int)" << endl;
	}
#endif

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

private:
	int _ix;
	int _iy;
};
 
int main(void)
{
	Point pt;
	pt.print();

	//Point pt2(1, 2);
	//pt2.print();

	int a = 1, b = 2;
	a = b;//赋值语句

	return 0;
}
