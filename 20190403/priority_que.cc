 ///
 /// @file    priority_que.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-11-07 15:20:43
 ///
 
#include <math.h>
#include <iostream>
#include <queue>
#include <vector>
using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;

void test0()
{
	int arr[9] = {5, 3, 2, 7, 4, 6, 1, 8, 9};

	//优先级队列默认情况下是大顶堆, 比较方式是小于, 元素的排列是降序的
	//优先级队列的底层实现是堆排序, 当堆顶元素与新来元素进行比较时，
	//满足条件，就将新来元素替换成堆顶元素; 不满足就不操作
	priority_queue<int> pque;
	for(int idx = 0; idx != 9; ++idx) {
		pque.push(arr[idx]);
		cout << "此时优先级队列中级别最高的元素是: " << pque.top() << endl;
	}

	while(!pque.empty()) {
		cout << pque.top() << " ";
		pque.pop();
	}
	cout << endl;
}
 
void test1()
{
	int arr[9] = {5, 3, 2, 7, 4, 6, 1, 8, 9};

	priority_queue<int, vector<int>, std::greater<int>> pque;
	for(int idx = 0; idx != 9; ++idx) {
		pque.push(arr[idx]);
		cout << "此时优先级队列中级别最高的元素是: " << pque.top() << endl;
	}

	while(!pque.empty()) {
		cout << pque.top() << " ";
		pque.pop();
	}
	cout << endl;
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
	friend bool operator>(const Point & lhs, const Point & rhs);

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

bool operator>(const Point & lhs, const Point & rhs)
{
	return lhs.getDistance() > rhs.getDistance();
}

void test2()
{
	Point arr[5] = {
		{1, 8}, 
		{2, 7}, 
		{4, 6}, 
		{5, 3},
		{9, 1}
	};

	priority_queue<Point, vector<Point>, std::greater<Point>> pque;
	for(int idx = 0; idx != 5; ++idx) {
		pque.push(arr[idx]);
		cout << "此时优先级队列中级别最高的元素是: " << pque.top() << endl;
	}

	while(!pque.empty()) {
		cout << pque.top() << " ";
		pque.pop();
	}
	cout << endl;
}
int main(void)
{
	//test0();
	//test1();
	test2();
	return 0;
}
