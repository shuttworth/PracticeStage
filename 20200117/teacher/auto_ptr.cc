 ///
 /// @file    auto_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-17 11:35:14
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::auto_ptr;

class Point
{
public:
	Point(int x = 0, int y = 0)
	: _x(x)
	, _y(y)
	{
		cout << "Point(int,int)" << endl;
	}

	void print() const 
	{
		cout << "(" << _x
			 << "," << _y
			 << ")" << endl;
	}

	~Point() {	cout << "~Point()" << endl;}

private:
	int _x;
	int _y;
};

void test0()
{
	Point * p = new Point(1, 2);
	auto_ptr<Point> ap(p);
	cout << "ap'get(): " << ap.get() << endl
		 << "p： " << p << endl;

	ap->print();
	(*ap).print();
	cout << endl;

	//该语句在语法形式上来说，是一个复制操作
	//但底层已经发生了所有权的转移,是矛盾的
	//
	//该智能指针存在缺陷, 已经被废弃
	//
	auto_ptr<Point> ap2(ap);
	ap2->print();
	(*ap2).print();

	ap->print();
	(*ap).print();

	cout << "..." << endl;
}

void test1()
{
	Point * pt = new Point(1, 2);
	auto_ptr<Point> ap1(pt);
	auto_ptr<Point> ap2(pt);
}
 
int main(void)
{
	/* test0(); */
	test1();

	return 0;
}
