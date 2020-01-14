 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-09 10:05:41
 ///
 
#include <math.h>

#include <iostream>
using std::cout;
using std::endl;

//using namespace std;


class Point;//类的前向声明

class Line
{
public:
	//成员函数的声明
	float distance(const Point & lhs, const Point & rhs);
	void setPoint(Point * pt, int ix, int iy);

private:
	int _a;
};

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	void print() const 
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" ;
	}

	//从这里可以看出: 友元关系是单向的
	void setA(Line & line, int a)
	{
		line._a = a;//error
	}

	//友元之友元类
	//friend Line;//之前已经有类的声明或定义
	friend class Line;//之前没有类的声明或定义
	//友元关系不具备传递性、不能被继承

private:
	int _ix;
	int _iy;
};


float Line::distance(const Point & lhs, const Point & rhs)
{
	return sqrt((lhs._ix - rhs._ix) * (lhs._ix - rhs._ix) +
		   (lhs._iy - rhs._iy) * (lhs._iy - rhs._iy));
}
 
void Line::setPoint(Point * pt, int ix, int iy)
{
	pt->_ix = ix;
	pt->_iy = iy;
}

int main(void)
{
	Point pt1(1, 2), pt2(3, 4);
	pt1.print();
	cout << " ----> ";
	pt2.print();
	cout << "的距离:" << Line().distance(pt1, pt2) << endl;
	cout << endl;
	Line().setPoint(&pt2, 11, 12);
	cout << "pt2:";
	pt2.print();

	return 0;
}
