#include <math.h>
#include <iostream>
using std::cout;
using std::endl;
//using namespace std;

class Complex
{
public:
	Complex(double dreal = 0, double dimag = 0)
	: _dreal(dreal)
	, _dimag(dimag)
	{	cout << "Complex(double,double)" << endl;	}

	friend std::ostream & operator<<(std::ostream & os, const Complex & rhs);
private:
	double _dreal;
	double _dimag;
};

std::ostream & operator<<(std::ostream & os, const Complex & rhs)
{
	if(rhs._dreal != 0) {
		os << rhs._dreal;
	} 
	if(rhs._dimag > 0)
		os << " + " << rhs._dimag << "i";
	
	else if (rhs._dimag < 0) 
		os << " - " << rhs._dimag * (-1) << "i";
	else
		os << rhs._dimag;
	
	return os;
}

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
			 << ")" << endl;
	}
	// 类型转换函数
	//1. 成员函数形式
	//2. 没有返回值, 但在函数执行体内必须以return语句返回一个目标类型的变量
	//3. 没有参数
	//4. 能不使用尽量不要使用
	operator int()
	{
		cout << "operator int()" << endl;
		return _ix;	
	}

	operator double()
	{	
		cout << "operator double()" << endl;
		return _ix * _iy;	
	}

	operator Complex()
	{
		cout << "operator Complex()" << endl;
		return Complex(_ix, _iy);
	}

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
	Point pt1(1, 2);
	int x = pt1;
	cout << "x = " << x << endl;
	double y = pt1;
	cout << "y = " << y << endl; 

	Complex c1 = pt1;
	cout << "c1 = " << c1 << endl;
	return 0;
}
