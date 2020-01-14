 ///
 /// @file    Point4.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-03 17:23:24
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	//引用数据成员只能在构造函数的初始化列表
	//之中进行初始化
	Point(int ix = 0, int iy = 0)
	//Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int=0, int=0)" << endl;
	}

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")";
	}

private:
	int _ix;
	int _iy;
};


class Line
{
public:
	//当类中出现了对象成员时，即使不显式初始化对象成员，
	//也会调用相应的默认构造函数进行初始化;
	//
	//如果不希望调用默认构造函数，则需要在
	//初始化列表之中显式调用相应构造函数初始化对象成员
	Line(int x1, int y1, int x2, int y2)
	: _pt1(x1, y1)
	, _pt2(x2, y2)
	{
		cout << "Line(int,int,int,int)" << endl;
	}

	void printLine() 
	{
		_pt1.print();
		cout << " ---> ";
		_pt2.print();
		cout << endl;
	}

private:
	Point _pt1;//对象成员
	Point _pt2;
};
 
int main(void)
{
	Line line(1, 2, 3, 4);
	line.printLine();
 
	return 0;
}
