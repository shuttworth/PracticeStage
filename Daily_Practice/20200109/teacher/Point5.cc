 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-09 10:05:41
 ///
 
#include <math.h>

#include <iostream>
#include <limits>
using std::cout;
using std::endl;

//using namespace std;



class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	//以下两个函数在该类中被删除了
	Point(const Point & rhs) = delete;
	Point & operator=(const Point & rhs) = delete;

	void print() const 
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" ;
	}

	//不能这样写, 输出流运算符不能作为成员函数重载
	//左左操作数必须是流对象;如果以成员函数形式重载，
	//左操作数就是对象本身了, 所以是矛盾的
	//operator<<(std::ostream & os)


	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
	friend std::istream & operator>>(std::istream & is, Point & rhs);
	friend bool operator==(const Point & lhs, const Point & rhs);

private:
	int _ix;
	int _iy;
};

//所有的流对象是不能进行复制的
//流对象传递时，只能以引用形式进行传递
std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix 
	   << "," << rhs._iy
	   << ")";
	return os;
}

void readInteger(std::istream & is, int & number)
{
	cout << "pls input a valid integer:" << endl;
	while(is >> number, !is.eof()) {
		if(is.bad()) {
			std::cerr << "istream has corupted\n";
			return;
		} 
		if(is.fail()) {
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "pls input a valid integer:" << endl;
			continue;
		}
		break;
	}
}

std::istream & operator>>(std::istream & is, Point & rhs)
{
	//is >> rhs._ix;
	//is >> rhs._iy;
	readInteger(is, rhs._ix);
	readInteger(is, rhs._iy);
	return is;
}

bool operator==(const Point & lhs, const Point & rhs)
{
	return (lhs._ix == rhs._ix) && 
		   (lhs._iy == rhs._iy);
}

bool operator!=(const Point & lhs, const Point & rhs)
{
	return !(lhs == rhs);
}

int main(void)
{
	Point pt1(1, 2), pt2(3, 4);
	cout << "pt1 = " << pt1 << endl
		 << "pt2 = " << pt2 << endl;
	
	//pt1 = pt2;//error

	//Point pt3 = pt1;//error
	//pt1 << cout;

	//std::cin >> pt1;
	//cout << "pt1: " << pt1 << endl;

	cout << (pt1 == pt2) << endl;

	return 0;
}
