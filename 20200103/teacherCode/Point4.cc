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
	//const数据成员只能在构造函数的初始化列表
	//之中进行初始化
	Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
	{
		//_ix = ix;
		//_iy = iy;
	}

	void print()
	{
		//_ix = 100;//error  只读, 不能修改
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

private:
	const int _ix;
	const int _iy;
};
 
int main(void)
{
	Point pt(11, 11);
	pt.print();
 
}
