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
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int=0,int =0)" << endl;
	}

	~Point()
	{	cout << "~Point()" << endl;	}

	void print() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

private:
	int _ix;
	int _iy;
};
 
int main(void)
{
	/* Point pts[5] = {Point(1, 2), Point(3, 4)}; */
	/* pts[0].print(); */
	/* pts[1].print(); */
	/* pts[2].print(); */

	//Point * pt1 = (Point*)malloc(sizeof(Point) * 3);
 
	//delete [] pt1;

	return 0;
}
