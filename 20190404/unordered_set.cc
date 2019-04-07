#include <math.h>
#include <iostream>
#include <unordered_set>
using std::cout;
using std::endl;
using std::unordered_set;
 
int test0(void)
{
	//unordered_set 不能存放关键字相同的元素，无序的
	//底层实现采用的是散列表

	unordered_set<int> numbers = {3, 2, 1, 4, 5, 2, 3, 4, 5, 6};

	unordered_set<int>::iterator it;
	for(it = numbers.begin(); it != numbers.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	//时间复杂度为O(1)
	cout << numbers.count(1) << endl;
	cout << numbers.count(0) << endl;

	it = numbers.find(6);
	if(it != numbers.end())
		cout << "查找成功:" << *it << endl; 
	else
		cout << "查找失败" << endl;

	return 0;
}

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int=0,int=0)" << endl;
	}
	
	void print() const
	{
		cout << "(" << _ix 
			 << "," << _iy
			 << ")" << endl;
	}

	float getDistance() const
	{
		return sqrt(_ix * _ix + _iy * _iy);
	}

	int getX() const {	return _ix;	}
	int getY() const {	return _iy;	}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
	friend bool operator==(const Point & lhs, const Point & rhs);

private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}

bool operator==(const Point & lhs, const Point & rhs)
{
	return (lhs._ix == rhs._ix) && (lhs._iy == rhs._iy);
}

struct MyEqual
{
	bool operator()(const Point & lhs, const Point & rhs) const
	{
		return (lhs.getX()== rhs.getX()) && (lhs.getY()== rhs.getY());
	}
};

namespace std
{
template <>
struct hash<Point>
{
	//自定义hash函数
	size_t operator()(const Point & pt) const
	{
		return 	(pt.getX() << 1) ^ (pt.getY() >> 1);
	}
};
}//end of namespace std

struct MyHasher
{
	size_t operator()(const Point & pt) const
	{
		return 	(pt.getX() << 1) ^ (pt.getY() >> 1);
	}
};


int test1(void)
{
	//unordered_set 不能存放关键字相同的元素，无序的
	//底层实现采用的是散列表

	unordered_set<Point> numbers = {
		{3, 2},
		{1, 4}, 
		{5, 2}, 
		{3, 4},
		{5, 6},
		{1, 4},
		{3, 2}
	};

	unordered_set<Point>::iterator it;
	for(it = numbers.begin(); it != numbers.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	//时间复杂度为O(1)
	cout << numbers.count({1, 4}) << endl;
	cout << numbers.count({0, 0}) << endl;

	it = numbers.find({1, 4});
	if(it != numbers.end())
		cout << "查找成功:" << *it << endl; 
	else
		cout << "查找失败" << endl;

	return 0;
}

int test2(void)
{
	//unordered_set 不能存放关键字相同的元素，无序的
	//底层实现采用的是散列表

	unordered_set<Point, MyHasher, MyEqual> numbers = {
		{3, 2},
		{1, 4}, 
		{5, 2}, 
		{3, 4},
		{5, 6},
		{1, 4},
		{3, 2}
	};

	unordered_set<Point>::iterator it;
	for(it = numbers.begin(); it != numbers.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}

int main(void)
{
	test0();
	//test1();
	//test2();
	return 0;
}
