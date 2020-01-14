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

	friend std::ostream & operator<<(std::ostream & os, const Fraction & rhs);


	//类型转换函数
	//特点:
	//1. 成员函数
	//2. 函数形式上没有返回值，没有参数
	//3. 在函数体内又必须以return语句返回一个
	//   目标类型的对象
	//
	//4. 一般情况下不使用  
	operator double() {
		cout << "operator double()" << endl;
		return _numerator / _denominator;
	}

	operator Point()
	{	
		cout << "operator Point()" << endl;	
		return Point(_numerator, _denominator);
	}

private:
	double _numerator;//分子
	double _denominator;//分母
};
 
std::ostream & operator<<(std::ostream & os, const Fraction & rhs)
{
	os << rhs._numerator << "/"
	   << rhs._denominator;
	return os;
}

int main(void)
{
	Fraction f(1, 2);
	cout << "f = " << f << endl;
	double x = f;//将自定义类型转换成其他类型
	cout << "x = " << x << endl;
	Point pt = f;//违反常规思维
	cout << "pt = " << pt << endl;

	return 0;
}
