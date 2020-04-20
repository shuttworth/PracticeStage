#include <iostream>
#include <vector>
#include <deque>
#include <list>
using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int,int)" << endl;}

	~Point()
	{	cout << "~Point()" << endl;}

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

template <typename Container>
void display(const Container & c)
{
	typename Container::const_iterator cit = c.begin();
	while(cit != c.end()) {
		cout << *cit << " ";
		++cit;
	}
	cout << endl;
}

void test0()
{
	//vector<int> numbers(10, 1);
	//vector<int> numbers(10, 1);
	//int arr[5] = {1, 2, 3, 4, 5};
	//vector<int> numbers(arr, arr + 4);// 迭代器范围[ )    左闭右开
	
	vector<int> numbers{1, 2, 3, 4, 5, 6};//C++11
	
	int arr[3] = {11, 12, 13};
	auto vit = numbers.begin();
	std::advance(vit, 3);  //advance实现向前偏移N个元素
//	numbers.insert(numbers.begin(), 0);//O(N)
//	numbers.insert(++numbers.begin(), -1);
	numbers.insert(vit, arr, arr + 3);//O(N)  在vector中间位置添加元素，其时间复杂度为O(N)
	numbers.shrink_to_fit();// 释放多余的空间

	cout << "numbers's size = " << numbers.size() << endl;
	cout << "numbers's capacity = " << numbers.capacity() << endl;

	display(numbers);

}
 
void test1()
{
	vector<Point> numbers(10, Point(1, 2));
	vector<Point>::iterator it;

	for(it = numbers.begin(); it != numbers.end(); ++it) {  //begin 和 end 是左闭右开的区间，end-begin正好是元素总个数
		cout << *it << " ";
	}

	cout << "vector  numbers[3] = " << numbers[3] << endl;
	cout << endl;
}

void test2()  //deque的用法
{
	//vector<int> numbers(10, 1);
	//vector<int> numbers(10, 1);
	//int arr[5] = {1, 2, 3, 4, 5};
	//deque<int> numbers(arr, arr + 5);// 迭代器范围[ )    左闭右开
	
	deque<int> numbers{1, 2, 3, 4, 5, 6};//C++11
	
	int arr[3] = {11, 12, 13};
	auto vit = numbers.begin();
	std::advance(vit, 3);//向前偏移迭代器3个位置
//	numbers.insert(numbers.begin(), 0);//O(N)
//	numbers.insert(++numbers.begin(), -1);
	numbers.insert(vit, arr, arr + 3);//O(N)  在deque中间位置添加元素，其时间复杂度为O(N)

	cout << "deque numbers[3] = " << numbers[3] << endl;//随机访问
	//numbers.push_front(0);//O(1)
	//numbers.push_back(6);//O(1)
	display(numbers);

}
void test3()
{
	//vector<int> numbers(10, 1);
	//vector<int> numbers(10, 1);
	//int arr[5] = {1, 2, 3, 4, 5};
	//list<int> numbers(arr, arr + 5);// 迭代器范围[ )    左闭右开
	
	list<int> numbers{1, 2, 3, 4, 5, 6};//C++11
	//cout << "list numbers[3] = " << numbers[3] << endl;// list不支持随机访问, 没有重载下标访问运算符
	
	int arr[3] = {11, 12, 13};
	auto vit = numbers.begin();
	std::advance(vit, 3);//向后偏移迭代器3个位置
//	numbers.insert(numbers.begin(), 0);//O(1)
//	numbers.insert(++numbers.begin(), -1);//O(1)
	numbers.insert(vit, arr, arr + 3);//O(N)  在list中间位置添加元素，其时间复杂度为O(1)
	//numbers.push_front(0);//O(1)
	//numbers.push_back(6);

	display(numbers);
	numbers.clear();  //clear操作清空元素，但没有释放空间
	cout << "执行clear操作之后:";
	display(numbers);
}

int main(void)
{
	//test0();
	//cout << endl;
	//test1();
	test2();
	//test3();
	return 0;
}
