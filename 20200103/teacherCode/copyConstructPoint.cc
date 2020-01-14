 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-03 09:58:24
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:

	Point(int x = 0, int y = 0)
	: _ix(x)
	, _iy(y)
	{
		cout << "Point(int,int)" << endl;
	}

	//系统自动提供一个拷贝构造函数, 固定写法
	//1. 引用符号不能去掉，如果去掉，根据拷贝构造函数的
	//调用时机来看，会导致无穷递归，直到栈溢出，程序崩溃
	//2. const关键字不能去掉，如果去掉，当传递过来的是
	//右值时，就无法正确调用拷贝构造函数
	Point(const Point & rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
		cout << "Point(const Point &)" << endl;
	}

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

private:
	int _ix;
	int _iy;
};
 
int test(void)
{
	Point pt(1, 2);
	cout << "pt:";
	pt.print();

	Point pt2 = pt;//调用拷贝构造函数
				   //Point(const Point rhs)
				   //const Point rhs = pt;
				   //
				   //Point(const Point rhs)
				   //const Point rhs = pt;
				   //
				   //Point(const Point rhs)
				   //const Point rhs = pt;
	cout << "pt2:";
	pt2.print();

	Point pt3(pt2);

	return 0;
}

void func(Point pt)  //Point pt = p;
{
	cout << "pt:";
	pt.print();
}

Point func2()
{
	Point pt(1, 2);
	cout << "pt:";
	pt.print();
	
	//编译器有优化的操作，如果要看到完整的过程
	//需要加上编译选项 -fno-elide-constructors
	return pt;
}

int getValue()
{
	int x = 1;
	return x;
}

void test2()
{
	Point p(1, 2);
	func(p);
}

void test3()
{
	int number = 1;
	int & ref = number;// 非const左值引用 不能绑定到右值
	&number;//能够取地址 => 左值
	cout << "ref = " << ref << endl;
	cout << "&ref = " << &ref << endl;
	ref = 10;

	//int & ref2 = 1;//error
	const int & ref3 = 1;//const左值引用可以绑定到右值
	cout << "ref3 = " << &ref3 << endl;

	//&1; //error字面值常量, 无法取地址 => 右值
}

void test4()
{
	//&func2();//error 临时对象, 不能取地址 ==> 右值
	//Point p = func2();//Point(Point & rhs)
	//Point & rhs = func2();//error
	//const Point & ref = func2();
	const Point & rhs = Point(3, 4);
	cout << "&rhs:" << &rhs << endl;

	//cout << "p:";
	//p.print();
	
	Point(1, 2).print();
	//&Point(3, 4);
	Point pt(3, 4);//有名对象
	Point(3, 4);//匿名对象, 临时对象, 右值, 
		        //非持久化对象，只在该语句存在
}

int main(void)
{
	//test();
	//test2();
	//test3();
	test4();

	return 0;
}
