 ///
 /// @file    Point4.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-03 17:23:24
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	//引用数据成员只能在构造函数的初始化列表
	//之中进行初始化
	Point(int ix, int iy, int & iz)
	: _ix(ix)
	, _iy(iy)
	, _iz(iz)
	{
		_iz = iz;
		//_ix = ix;
		//_iy = iy;
	}

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << "," << _iz
			 << ")" << endl;
	}

private:
	const int _ix;
	const int _iy;
	int & _iz;
};
 
int main(void)
{
	int number = 100;
	Point pt(11, 11, number);
	pt.print();
 
	return 0;
}
