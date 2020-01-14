#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	//禁用隐式转换
	explicit
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

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
	//Point pt1 = 1;//存在隐式转换
	//pt1.print();

	//string的隐式转换是希望进行的
	std::string s1 = "hello,world";

	//std::string s2("hello,world");

	return 0;
}
