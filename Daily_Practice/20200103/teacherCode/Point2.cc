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
#if 1
	//构造函数在执行时，先执行初始化表达式，再执行
	//构造函数执行体
	Point()
	: _ix(0), _iy(0)    //构造函数初始化表达式
	{
		//_ix = 0;//赋值语句
		//_iy = 0;
		cout << "Point()" << endl;
	}

	Point(int val)
	: _iy(val)
	, _ix(_iy)
	{
		cout << "Point(int)" << endl;
	}

	Point(int x, int y)
	: _ix(x)
	, _iy(y)
	{
		//_ix = x;
		//_iy = y;
		cout << "Point(int,int)" << endl;
	}
#endif

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	//析构函数
	//	清理工作
	~Point()
	{
		cout << "~Point()" << endl;
	}

private:
	int _ix;
	int _iy;
};
 
int test(void)
{
	Point pt;
	pt.print();

	//Point pt2(1, 2);
	//pt2.print();


	int a = 1, b = 2;
	a = b;//赋值语句

	Point  pt3(b);//对象被销毁时，自动调用析构函数
	cout << "pt3:";
	pt3.print();
	return 0;
}

int main(void)
{
	test();
	return 0;
}
