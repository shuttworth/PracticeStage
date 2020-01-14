 ///
 /// @file    set.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-13 17:19:05
 ///
 
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::set;
using std::map;
using std::vector;
using std::string;

void test0()
{
	cout << ">> test0(): " << endl;
	//int arr[5] = {3, 2, 1, 4, 5};
	int arr[5] = {5, 4, 3, 2, 1};
	//set内部的元素按照从小到大的顺序进行排列
	//set内部不能存放关键字相同的元素
	//
	//它的底层实现是 红黑树
	set<int> numbers{11, 20, 30, 20, 40};

	numbers.insert(1);
	numbers.insert(2);
	numbers.insert(arr, arr + 5);//迭代器范围是一个左闭右开的区间

	for(auto & number : numbers) {
		cout << number << " ";
	}
	cout << endl;
	//set不支持下标访问运算符
	//cout << numbers[1] << endl;//error

	//嵌套类/内部类
	//迭代器可以看成是一个指针
	//set<int>::iterator it;
	for(auto it = numbers.begin(); it != numbers.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	//查找元素
	cout << numbers.count(1) << endl;
	cout << numbers.count(0) << endl;

	auto it2 = numbers.find(5);
	if(it2 == numbers.end()) {
		cout << "查找元素失败！" << endl;
	} else 
		cout << *it2 << endl;

	//*it2 = 100;//error 放入set放的元素是不能修改的
}

void test1()
{
	cout << endl << ">> test1:" << endl;
	vector<int> numbers{1, 2, 3, 4, 5};

	//vector<int>::iterator it;
	for(auto it = numbers.begin(); it != numbers.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	cout << numbers[1] << endl;
}


void test2()
{
	cout << endl << ">> test2:" << endl;
	//map<string, string> cities;
	//map之中不能存放关键字相同的元素
	//map中默认情况下，会按关键字进行排序(升序)
	//
	//底层实现是红黑树
	map<string, string> cities
	{
		{"027", "武汉"},
		{"010", "北京"},
		{"022", "天津"},
		{"021", "上海"},
		{"021", "南京"},
		std::pair<string, string>("023", "重庆")
	};

	for(auto & city : cities) {
		cout << city.first << " --> "
			 << city.second << endl;
	}

	//pair<iterator, bool>
	auto ret = cities.insert({"021", "南京"});
	if(ret.second) {
		cout << "添加成功\n" << endl;
		cout << ret.first->first << " ---> "
			 << ret.first->second << endl;
	} else {
		cout << "添加失败，容器中已有相同关键字的元素" << endl;
	}

	//map支持下标访问运算符
	
	//如果key存在，则直接获取对应的value的内容
	//如果key不存在，则添加一个以当前key为关键字的新元素
	cout << "下标访问运算符: " 
		 << endl << cities["021"] << endl
		 << cities["北京"] << endl;

	for(auto & city : cities) {
		cout << city.first << " --> "
			 << city.second << endl;
	}

	//时间复杂度是O(logN)
	cities["北京"] = "110";//进行修改
	cities["0755"] = "深圳";//添加新元素
	for(auto & city : cities) {
		cout << city.first << " --> "
			 << city.second << endl;
	}
}
 
int main(void)
{
	/* test0(); */
	/* test1(); */
	test2();
	return 0;
}
