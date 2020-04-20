 ///
 /// @file    unique_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-16 17:53:27
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;

using std::unique_ptr;

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

unique_ptr<Point> getValue()
{
	unique_ptr<Point> tmp(new Point(11, 12));
	return tmp;
}

void test0()
{
	//Point * pt1 = new Point(1, 2);
	//默认情况下，当unique_ptr被销毁时，会执行delete表达式
	//之后所以的操作都交给up进行
	//
	//在C++11之中不希望直接使用原始的裸指针
	//
	unique_ptr<Point> up(new Point(1, 2));
	//cout << "pt1: " << pt1 << endl
	cout << "up.get():" << up.get() << endl;//获取资源的地址
	up->print();//操作up跟操作pt1是一样的
	(*up).print();

	//unique_ptr<Point> up2(up);//error  表达对象语义, 禁止复制
	//独享所有权的智能指针
	unique_ptr<Point> up2(std::move(up));//ok

	
	//unique_ptr内部定义了具有移动语义的函数
	unique_ptr<Point> up3 = getValue();
	up3->print();

	cout << endl << "sizeof(up): " << sizeof(up) << endl;
}

void test1()
{   
	//Point pt(1, 2);
	//unique_ptr<Point> up0(&pt);
	//托管的指针值就是空指针
	unique_ptr<Point> up;
	cout << "sizeof(up): " << sizeof(up) << endl;
	cout << "up.get():" << up.get() << endl;

    
    //unique_ptr<Point> up2 = up;
	//cout << "up2.get():" << up.get() << endl;
}
int main(void)
{
	 test0(); 
	//test1();

	return 0;
}
