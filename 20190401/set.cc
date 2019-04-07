#include <math.h>
#include <iostream>
#include <set>
using std::cout;
using std::endl;
using std::set;

template <typename Container>
void display(const Container & c)
{
	for(auto & elem : c) {
		cout << elem << " ";
	}
	cout << endl;
}

void test0()
{
	//set之中不能存放关键字相同的元素, 默认情况下按升序排列
	int arr[10] = {4, 4, 2, 3, 2, 1, 5, 6, 2, 1};
	set<int> numbers(arr, arr + 10);
	display(numbers);

	//cout << numbers[0];//set不支持下标访问运算符
	
	//查找,某个元素在不在这之中
	size_t cnt = numbers.count(1);
	cout << "cnt = " << cnt << endl;
	cnt = numbers.count(7);
	cout << "cnt = " << cnt << endl;

	set<int>::iterator it = numbers.find(1);
	cout << "*it = " << *it << endl;
	//
	//set的底层实现是红黑树, 是一颗近似的平衡二叉树(AVL) 
	//	--> 左右子树高度差不超过1 
	//	--> 时间复杂度为O(logN)
	//	--> 二分查找
	//
	//1. 节点不是红色就是黑色
	//2. 根节点是黑色
	//3. 空节点都是黑色
	//4. 红色节点的孩子都是黑色
	//5. 从任意节点到孩子节点的路径中，黑色节点必须是相同的
	//*it = 10;//error, set之中的元素不能进行修改??? 因为其底层实现是红黑树，如果修改，有可能破坏红黑树的结构
}
 
void test1()
{
	//set之中不能存放关键字相同的元素, 默认情况下按升序排列
	int arr[10] = {4, 4, 2, 3, 2, 1, 5, 6, 2, 1};
	set<int, std::greater<int>> numbers(arr, arr + 10);
	display(numbers);

	//cout << numbers[0];//set不支持下标访问运算符
	
	//查找
	size_t cnt = numbers.count(1);
	cout << "cnt = " << cnt << endl;
	cnt = numbers.count(7);
	cout << "cnt = " << cnt << endl;

	set<int>::iterator it = numbers.find(1);
	cout << "*it = " << *it << endl;
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

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);

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

#if 0
bool operator<(const Point & lhs, const Point & rhs)
{
	return lhs.getDistance() < rhs.getDistance();
}
#endif

struct Compare //自己重新定义一个函数对象
{
	bool operator()(const Point & lhs, const Point & rhs)
	{
		return lhs.getDistance() < rhs.getDistance();
	}
};

void test2(void)   //set容器的存放类型，除了int型，亦可存放自定义类型的，如本例
{
	//set<Point> points{
	set<Point, Compare> points{  //不用小于号,Compare函数对象也可实现
		Point(1, 2),
		Point(2, 3),
		Point(-1, -1),
		Point(2, 3),
		Point(5, 6),
		Point(3, 4)
	};
	display(points);
}

int main(void)
{
	//test1();
	test2();
	return 0;
}
