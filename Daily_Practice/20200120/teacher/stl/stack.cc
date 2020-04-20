 ///
 /// @file    stack.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-20 15:20:30
 ///
 
#include <iostream>
#include <stack>
using std::cout;
using std::endl;
using std::stack;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{}

	friend std::ostream & operator<<(std::ostream & os, const Point &);

private:
	int _ix;
	int _iy;
};
 
std::ostream & operator<<(std::ostream & os, const Point &rhs)
{
	os << "(" << rhs._ix 
	   << "," << rhs._iy
	   << ")";
	return os;
}
int main(void)
{
	stack<Point> points;
	points.push(Point(1, 2));
	points.emplace(3, 4);// 可以减少复制的开销, 效率更高一些

	while(!points.empty()) {
		cout << points.top() << " ";
		points.pop();
	}

	return 0;
}
