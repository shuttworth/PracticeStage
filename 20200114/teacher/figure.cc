///
/// @file    figure.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2020-01-14 16:47:15
///

#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

//作为接口存在
//
//面向对象设计原则之一: 开闭原则
//	  对扩展开放，对修改关闭
//

class Figure {
public:
	virtual void display() const =0;
	virtual double area() const =0;
};

class Circle
: public Figure {
public:
	explicit 
	Circle(double radius)
	: _radius(radius) {}

	void display() const {	cout << "Circle";	}

	double area() const 
	{	return 3.14159 * _radius * _radius;	}
private:
	double _radius;
};

class Rectangle
: public Figure {
public:
	Rectangle(double length, double width)
	: _length(length)
	, _width(width)
	{}

	void display() const {	cout << "Rectangle";	}

	double area() const {	return _length * _width;	}
private:
	double _length;
	double _width;
};

class Triangle
: public Figure {
public:
	Triangle(double a, double b, double c)
	: _a(a)
	, _b(b)
	, _c(c)
	{}

	void display() const {	cout << "Triangle";	}

	double area() const {	
		double p = (_a + _b + _c) / 2;
		return  sqrt(p * (p - _a) * (p - _b) * (p - _c));
	}    
private:
	double _a;
	double _b;
	double _c;
};

void test(Figure & fig)
{
	fig.display();
	cout << "的面积是" << fig.area() << endl;
}

int main(void)
{
	Circle circle(10);
	Rectangle rectangle(3, 4);
	Triangle triangle(3, 4, 5);

	test(circle);
	test(rectangle);
	test(triangle);
	return 0;
}
