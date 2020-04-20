 ///
 /// @file    Fraction.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-10 15:19:17
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int,int)" << endl;	}

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

class Fraction
{
public:
	Fraction(double numerator, double denominator)
	: _numerator(numerator)
	, _denominator(denominator)
	{}

	//explicit
	operator double() {
		cout << "operator double()" << endl;
		return _numerator / _denominator;
	}

	/* operator Point() */
	/* { */	
	/* 	cout << "operator Point()" << endl; */	
	/* 	return Point(_numerator, _denominator); */
	/* } */

private:
	double _numerator;//分子
	double _denominator;//分母
};
 
#if 0
std::ostream & operator<<(std::ostream & os, const Fraction & rhs)
{
	os << rhs._numerator << "/"
	   << rhs._denominator;
	return os;
}
#endif

int main(void)
{
	Fraction f(1, 2);
	cout << "f = " << f << endl;

	//double x = f;//将自定义类型转换成其他类型
	//cout << "x = " << x << endl;
	//Point pt = f;//违反常规思维
	//cout << "pt = " << pt << endl;

	return 0;
}
