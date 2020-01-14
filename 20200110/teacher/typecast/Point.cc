 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-10 15:08:47
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Complex
{
public:
	Complex(double dreal, double dimage)
	: _dreal(dreal)
	, _dimage(dimage)
	{
		cout << "Complex(double,double)" << endl;
	}

	void print() const
	{
		cout << _dreal << " + " << _dimage << "i" << endl;
	}

	friend class Point;

private:
	double _dreal;
	double _dimage;
};

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int,int)" << endl;	}

	explicit
	Point(const Complex & rhs)
	: _ix(rhs._dreal)
	, _iy(rhs._dimage)
	{
		cout << "Point(const Complex&)" << endl;
	}

	~Point() {	cout << "~Point()" << endl;	}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);

private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}
 
int main(void)
{
	//将其他类型转换成自定义类型
	//	> 其他类型可以是内置类型，也可以是自定义类类型
	Point pt = 1;
	cout << "pt = " << pt << endl;

	Complex c1(11, 11);
	Point pt2 = c1;//存在隐式转换
	cout << "pt2 = " << pt2 << endl;

	return 0;
}
