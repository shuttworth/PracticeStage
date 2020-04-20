 ///
 /// @file    weak_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-17 15:19:32
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

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
	weak_ptr<Point> wp;
	//语句块
	{
		shared_ptr<Point> sp(new Point(1, 2));
		
		wp = sp;
		cout << "wp' use_count: " << wp.use_count() << endl
			 << "sp' use_count: " << sp.use_count() << endl;

		//weak_ptr没有重载 operator*(), operator->()
		//所以weak_ptr无法直接访问资源
		//
		//如果要访问资源，只能将weak_ptr提升成shared_ptr
		//lock方法就是用来进行提升的
		shared_ptr<Point> sp2 = wp.lock();
		cout << "wp's expired: " << wp.expired() << endl;
		if(sp2) {
			cout << "weak_ptr提升成功\n";
			sp2->print();
			cout << "sp2's use_count: " << sp2.use_count() << endl;
			
		} else {
			cout << "weak_ptr提升失败\n";
		}
	}
	cout << endl << "退出语句块之后:" << endl;

	cout << "wp's expired: " << wp.expired() << endl;
	cout << "wp' use_count: " << wp.use_count() << endl;
	shared_ptr<Point> sp2 = wp.lock();
	if(sp2) {
		cout << "weak_ptr提升成功\n";
		sp2->print();
	} else {
		cout << "weak_ptr提升失败\n";
	}
}

 
int main(void)
{
	test0();
 
	return 0;
}
