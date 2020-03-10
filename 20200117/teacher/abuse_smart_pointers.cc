 ///
 /// @file    abuse_smart_pointers.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-17 16:03:57
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;

class Point
: public std::enable_shared_from_this<Point>
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


	//Point * addPoint(Point * pt)
	//在类内部希望获取本对象的智能指针shared_ptr，
	//必须要继承自辅助类 std::enable_shared_from_this
	shared_ptr<Point> addPoint(Point * pt)
	{
		this->_x += pt->_x;
		this->_y += pt->_y;
		//return shared_ptr<Point>(this);
		return shared_from_this();
	}

private:
	int _x;
	int _y;
};


//智能指针误用的情况:
//	  将一个原生裸指针交给了2个不同的智能指针进行托管
void test0()
{
	Point * pt = new Point(1, 2);
	unique_ptr<Point> up(pt);
	unique_ptr<Point> up2(pt);
}

void test1()
{
	Point * pt = new Point(1, 2);
	//执行复制或者赋值时，引用计数加1
	shared_ptr<Point> up(pt);
	shared_ptr<Point> up2(pt);
}

void test2()
{
	//unique_ptr<Point> up(new Point(1, 2));
	shared_ptr<Point> sp(new Point(1, 2));
	unique_ptr<Point> up;
	unique_ptr<Point> up2(new Point(3, 4));

	//.....
	up.reset(up2.get());
}

void test3()
{
	shared_ptr<Point> sp(new Point(1, 2));
	shared_ptr<Point> sp2(sp);

	shared_ptr<Point> sp3(new Point(3, 4));

	cout << "sp's use_count:" << sp.use_count() << endl;
	cout << "sp2's use_count:" << sp2.use_count() << endl;
	cout << "sp3's use_count:" << sp3.use_count() << endl;
	cout << endl << "reset之后" << endl;
	
	//.....
	sp.reset(sp3.get());
	cout << "sp's use_count:" << sp.use_count() << endl;
	cout << "sp2's use_count:" << sp2.use_count() << endl;
	cout << "sp3's use_count:" << sp3.use_count() << endl;

	cout << "*sp: "; sp->print();
	cout << "*sp2: "; sp2->print();
	cout << "*sp3: "; sp3->print();

	cout << "...." << endl;
}

void test4()
{
	shared_ptr<Point> sp(new Point(1, 2));
	shared_ptr<Point> sp2(new Point(11, 12));

	shared_ptr<Point> sp3(sp->addPoint(sp2.get()));
}
 
int main(void)
{
	/* test0(); */
	/* test1(); */
	/* test2(); */
	/* test3(); */
	test4();
    const int & ref =0;
	return 0;
}
