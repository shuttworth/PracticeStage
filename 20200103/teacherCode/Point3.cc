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

	Point(const Point & rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
		cout << "Point(const Point &)" << endl;
	}


#if 1
	//void operator=(const Point & rhs)
	Point & operator=(const Point & rhs)
	{
		cout << "Point & operator=(const Point &)" << endl;
		_ix = rhs._ix;
		_iy = rhs._iy;

		return *this;
	}
#endif


	//隐含的this指针, 指向的是当前对象本身
	void print(/*   Point * const this   */ )
	{
		//this = 0x1000;
		//this->_ix = 1;
		//this->_iy = 1;
		cout << "(" << this->_ix
			 << "," << this->_iy
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
 
void test0()
{
	Point pt(1, 2);
	cout << "pt:";
	pt.print();// pt.print(&pt);
			   //==> Point::print(&pt); //编译器完成

	Point pt2(3, 4);
	cout << "pt2:";
	pt2.print();
}

void test1()
{
	int a = 1, b = 2, c = 3;
	a = (b = c);//连续赋值对内置类型的数据是可以的


	Point pt1(1, 2), pt2(11, 12);
	cout << "pt1:";
	pt1.print();
	pt1 = pt2; //调用赋值运算符函数
	//pt1.operator=(pt2);//完整形式
	cout << "pt1:";
	pt1.print();

	Point pt3(22, 23);
	pt1 = (pt2 = pt3);
}

int main(void)
{
	//test0();
	test1();
	return 0;
}
