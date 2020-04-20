///
/// @file    Point3D.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2020-01-13 14:49:54
///

#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int x, int y)
	: _x(x)
	, _y(y)
	{	cout << "Point(int,int)" << endl;}

	void print() const
	{
		cout << "(" << _x
			 << "," << _y
			 << ")";
	}


	~Point() {	cout << "~Point()" << endl;}

protected:
	int _x;
private:// 只在本类内部进行访问
	int _y;
};

class Point3D
: public Point  //接口继承
{
public:
	Point3D(int x, int y, int z)
	: Point(x, y)
	, _z(z)
	{
		cout << "Point3D(int,int,int)" << endl;
	}

	void display() const
	{
		print();
		cout << _x << endl;//ok  在派生类内部的范文权限是protected型的
		//cout << _y << endl;//error
		cout << _z << endl;
	}

	~Point3D() {	cout << "~Point3D()" << endl;}

private:
		int _z;
};

int main(void)
{
	Point3D pt1(1, 2, 3);
	pt1.print();//当采用public继承时，派生类对象只能基类public成员
			    //其他成员都不能进行访问
				//在派生类内部的访问权限是public
	//pt1._x;//error不可以访问
	//pt1._y;//error

	return 0;
}
