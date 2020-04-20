#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int =0,int=0)" << endl;	}


	//成员函数也可以是模板形式
	template <typename T>
	T typecast() 
	{
		return (T) _ix * _iy;
	}
	
private:
	int _ix;
	int _iy;
};
 
int main(void)
{
	Point pt(1, 2);
	double x = pt.typecast<double>();
	cout << "x = " << x << endl;
	return 0;
}
