#include "Line.h"

#include <math.h>
#include <iostream>
using std::cout;
using std::endl;
//using namespace std;


class Line::LinePimpl
{
	//嵌套类/内部类
	class Point   
	{
	public:
		Point(int ix = 0, int iy = 0)
		: _ix(ix)
		, _iy(iy)
		{
			cout << "Point(int=0,int=0)" << endl;
		}

		void print() const
		{
			cout << "(" << _ix
				 << "," << _iy
				 << ")";
		}

		~Point() {	cout << "~Point()" << endl;	}
	private:
		int _ix;
		int _iy;
	};
public:
	LinePimpl(int x1, int y1, int x2, int y2)
	: _p1(x1, y1)
	, _p2(x2, y2)
	{
		cout << "LinePimpl()" << endl;
	}

	void printLine() const
	{
		_p1.print();
		cout << " --> ";
		_p2.print();
		cout << endl;
	}

	~LinePimpl()
	{	cout << "~LinePimpl() " << endl;}

private:
	Point _p1;
	Point _p2;
};
 
Line::Line(int x1, int y1, int x2, int y2)
: _pimpl(new LinePimpl(x1, y1, x2, y2))
{
	cout << "Line(int, int,int,int)" << endl;
}

Line::~Line() 
{	
	if(_pimpl) delete _pimpl;	
	cout << "~Line()" << endl;
}

void Line::printLine() const
{
	_pimpl->printLine();
}

