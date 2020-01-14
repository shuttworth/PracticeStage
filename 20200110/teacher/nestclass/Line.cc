 ///
 /// @file    Line.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-10 16:09:37
 ///
 
#include "Line.h"
#include <iostream>
using std::cout;
using std::endl;

//实现层
class Line::LineImpl
{
public:
	LineImpl(int x1, int y1, int x2, int y2);
	~LineImpl();

	void printLine() const;

private:
	//嵌套类、内部类
	class Point
	{
	public:
		Point(int ix = 0, int iy = 0)
		: _ix(ix)
		, _iy(iy)
		{
			cout << "Point(int=0,int=0)" << endl;
		}

		void print() const;

		~Point() {	cout << "~Point()" << endl;	}
	private:
		int _ix;
		int _iy;
	};

private:
	Point _pt1;
	Point _pt2;
};

void Line::LineImpl::Point::print() const
{
	cout << "(" << _ix
		 << "," << _iy
		 << ")" << endl;
}

Line::LineImpl::LineImpl(int x1, int y1, int x2, int y2)
: _pt1(x1, y1)
, _pt2(x2, y2)
{
	cout << "LineImpl(int,int,int,int)" << endl;
}

Line::LineImpl::~LineImpl()
{	cout << "~LineImpl()" << endl;	}

void Line::LineImpl::printLine() const
{
	_pt1.print();
	cout << " ---> ";
	_pt2.print();
}


Line::Line(int x1, int y1, int x2, int y2)
: _pimpl(new LineImpl(x1, y1, x2, y2))
{
	cout << "Line(int,int,int,int)" << endl;
}

Line::~Line() 
{
	delete _pimpl;
	cout << "~Line()" << endl;
}

void Line::printLine() const
{
	_pimpl->printLine();
}

 
int main(void)
{
	Line line(1, 2, 3, 4);
	line.printLine();


	return 0;
}
