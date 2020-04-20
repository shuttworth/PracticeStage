 ///
 /// @file    sequence_container.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-20 16:07:22
 ///
 
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;
using std::set;

template <class Container>
void display(const Container & c)
{
	//在类内部使用作用域限定符访问的，包括
	//数据成员和自定义内部类
	//
	//加上typename，是告诉编译器这里是一个类类型
	//而不是数据成员
	//
	//
	//类型萃取技巧
	typename Container::value_type value;
	//
	typename Container::const_iterator it;
	for(it = c.begin(); it != c.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

void test00()
{
	set<int> numbers{3, 5, 8, 1, 0, 10};
	display(numbers);
}


void test0()
{
	cout << "vector test:" << endl;
	//int arr[10] = {1, 2, 3, 4, 5};
	//vector<int> numbers(10, 1);
	//vector<int> numbers(arr, arr + 5);
	//
	//1. vector底层实现就是3个指针进行维护的：
	//	 _start  _finish   _end_of_storage
	vector<int> numbers{1, 2, 3, 4, 5};
	cout << "numbers' size: " << numbers.size() << endl
		 << "numbers' capa: " << numbers.capacity() << endl;

	/* for(size_t idx = 1; idx != 100; ++idx) { */
	/* 	numbers.push_back(idx); */
	/* } */
	cout << "sizeof(numbers): " << sizeof(numbers) << endl;
	cout << "numbers' size: " << numbers.size() << endl
		 << "numbers' capa: " << numbers.capacity() << endl;

	display(numbers);

	//2.元素在头部与尾部的操作
	numbers.pop_back();
	display(numbers);
	//为什么vector没有在头部添加和删除元素的功能(方法/成员函数)?
	//如果这样做，其时间复杂度为O(N)
	

	//3.下标访问运算符, 时间复杂度为O(1)
	cout << "numbers[0]: " << numbers[0] << endl;

	//4.在任意位置添加或删除元素
	//insert/erase
	//时间复杂度O(n)
	numbers.insert(numbers.begin(), 100);
	display(numbers);
	auto it = numbers.begin();
	++it; ++it;
	numbers.insert(it, 3, 101);
	display(numbers);

	int arr[3] = {21, 22, 23};
	auto it2 = numbers.end();
	--it2; --it2;
	numbers.insert(it2, arr, arr + 3);
	display(numbers);
	auto it3 = numbers.begin();
	++it3; ++it3; ++it3;
	numbers.insert(it3, {31, 32, 33});
	display(numbers);

	//时间复杂度 O(N)
	numbers.erase(numbers.begin());
	display(numbers);
	cout << ">> clear之后：" << endl;
	numbers.clear();//清空容器中的元素
	//对于vector来说，没有回收空间
	display(numbers);
	cout << "numbers' size: " << numbers.size() << endl
		 << "numbers' capa: " << numbers.capacity() << endl;
}
 
void test1()
{
	cout << endl << endl << "deuqe test:" << endl;
	//deque<int> numbers(10, 1);
	//int arr[10] = {1, 2, 3, 4, 5};
	//deque<int> numbers(arr, arr + 5);
	//1.deque的底层是: N个片段组成的，
	//	片段内部是连续的，片段之间不一定连续
	//	片段之间是通过中控器联系起来的；
	//	对于元素的访问，deque的迭代器的实现至关重要
	deque<int> numbers{1, 2, 3, 4, 5};

	display(numbers);

	//2.元素在头部与尾部的操作
	numbers.push_front(10);//时间复杂度O(1)
	display(numbers);
	numbers.pop_back();
	display(numbers);
	
#if 0
	for(size_t idx = 1; idx != 100; ++idx) {
		numbers.push_back(idx);
	}
#endif
	cout << "sizeof(numbers): " << sizeof(numbers) << endl;
	//3.下标访问运算符, 时间复杂度为O(1)
	cout << "numbers[0]: " << numbers[0] << endl;

	//4.在任意位置添加或删除元素
	//insert/erase
	//时间复杂度O(n)
	numbers.insert(numbers.begin(), 100);
	display(numbers);

	auto it = numbers.begin();
	++it; ++it;
	numbers.insert(it, 3, 101);
	display(numbers);
	int arr[3] = {21, 22, 23};
	auto it2 = numbers.end();
	--it2; --it2;
	numbers.insert(it2, arr, arr + 3);
	display(numbers);
	auto it3 = numbers.begin();
	++it3; ++it3; ++it3;
	numbers.insert(it3, {31, 32, 33});
	display(numbers);
	//时间复杂度 O(N)
	numbers.erase(numbers.begin());
	display(numbers);
	numbers.clear();//清空容器中的元素
	display(numbers);

	//numbers.capacity();//error deque没有capacity方法
}

void test2()
{
	cout << endl << endl<< "list test:" << endl;
	//list<int> numbers(10, 1);
	//int arr[10] = {1, 2, 3, 4, 5};
	//list<int> numbers(arr, arr + 5);
	//1.list的底层实现:
	//	  循环双向链表
	list<int> numbers{1, 2, 3, 4, 5};
	display(numbers);

	//2.元素在头部与尾部的操作
	numbers.push_front(10);//时间复杂度O(1)
	display(numbers);
	numbers.pop_back();
	display(numbers);

#if 0
	for(size_t idx = 1; idx != 100; ++idx) {
		numbers.push_back(idx);
	}
#endif
	cout << "sizeof(numbers): " << sizeof(numbers) << endl;
	//3.list并不支持下标访问运算符
	//cout << "numbers[0]: " << numbers[0] << endl;
	//
	//4.在任意位置添加或删除元素
	//insert/erase
	//时间复杂度O(1)
	numbers.insert(numbers.begin(), 100);
	display(numbers);

	auto it = numbers.begin();
	++it; ++it;
	numbers.insert(it, 3, 101);
	display(numbers);

	int arr[3] = {21, 22, 23};
	auto it2 = numbers.end();
	--it2; --it2;
	numbers.insert(it2, arr, arr + 3);
	display(numbers);

	auto it3 = numbers.begin();
	++it3; ++it3; ++it3;
	numbers.insert(it3, {31, 32, 33});
	display(numbers);
	//时间复杂度 O(N)
	numbers.erase(numbers.begin());
	display(numbers);
	
	numbers.clear();//清空容器中的元素
	display(numbers);
}


int main(void)
{
	test00();
	test0();
	test1();
	test2();
 
	return 0;
}
