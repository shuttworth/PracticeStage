///
/// @file    String.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2020-01-14 11:11:34
///

#include <string.h>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;

class String {
public:
	String()
	: _data(new char[1]())
	{	cout << "String()" << endl;	}

	String(const char * data)
	: _data(new char[strlen(data) + 1]())
	{	
		cout << "String(const char * data)" << endl;	
		strcpy(_data, data);
	}
	//需求: 希望能够重复利用临时对象(右值)

	//问题： 当const引用作为函数参数时，无法确定
	//传递过来的是左值还是右值
	//
	//解决方案： 找到一种规则，能够识别出临时对象(右值)
	//		C++11 提供右值引用
	//
	//
	String(const String & rhs)
	: _data(new char[strlen(rhs._data) + 1]())
	{
		strcpy(_data, rhs._data);
		cout << "String(const String & )" << endl;
	}
	String & operator=(const String & rhs)
	{
		cout << "String & operator=(const String &)" << endl;
		if(this != &rhs) {
			delete [] _data;

			_data = new char[strlen(rhs._data) + 1]();
			strcpy(_data, rhs._data);
		}
		return *this;
	}

	//
	//当同时定义了复制控制语义的函数和具有移动语义的函数时
	//具有移动语义的函数会优先执行
	//
	//移动构造函数
	String(String && rhs)
	: _data(rhs._data)  //
	{
		cout << "String(&&)" << endl;
		rhs._data = nullptr;
	}

	//移动赋值运算符函数
	String & operator=(String && rhs)
	{	//右值引用本身已经变成了左值
		cout << "String & operator=(String&&)" << endl;
		if(this != &rhs) {
			delete [] _data;

			_data = rhs._data;//浅拷贝
			rhs._data = nullptr;//置为空指针
		}

		return *this;
	}


	~String()
	{
		cout << "~String()" << endl;
		delete [] _data;
	}

	const char * data() const
	{	return _data;	}

	friend std::ostream & operator<<(std::ostream & os, const String & rhs);

private:
	char * _data;
};


std::ostream & operator<<(std::ostream & os, const String & rhs)
{
	os << rhs._data;
	return os;
}


using std::vector;
void test1()
{
	String s1("hello");
	vector<String> strs;
	strs.push_back(s1);

	//放到容器中的元素是一份单独的拷贝
	cout << strs[0] << endl;
	cout << "&s1: " << &s1 << endl
		 << "&strs[0]: " << &strs[0] << endl;

}

void test2()
{
	vector<String> strs;
	
	//push_back会产生一个临时对象
	strs.push_back("hello,world");

	//希望重复利用产生的临时对象, 不希望频繁创建，频繁销毁
	
	String s1("hello");
	//const引用是一个万能引用
	const String & ref = String("hello,world");
	const String & ref1 = s1;

	cout << strs[0] << endl;

}

void test3()
{
	int number = 0;
	int && ref = 1;//右值引用只能绑定到右值
	//int && ref2 = number;//error 不能绑定到左值

	String refstr = String("hello");
	//String refstr(String("hello"));
	
	String s1 = "world";
	cout << "s1: " << s1 << endl;

	s1 = String("wuhan");
	cout << "s1: " << s1 << endl;
}

void test4()
{
	String s1 = "hello";
	cout << "s1:" << s1 << endl;
	//std::move显式将一个左值s1转换成右值
	//意味着该语句之后，不会再使用s1
	String s2 = std::move(s1);
	cout << "s2:" << s2 << endl;
#if 0
	cout << "s1:" << s1 << endl;
#endif
	s1 = "world";
	//但是s1的生命周期还没结束
	cout << "s1:" << s1 << endl;


	char * p1 = nullptr;
	int * p2 = nullptr;
	cout << p2 << endl;
	//当char*的指针为空时，程序会直接崩溃, bug, 程序执行的过程中不会报错
	cout << p1;

	cout << "....." << endl;

	s1 = std::move(s1);
}

void test5()
{
	int a = 1;//对于内置类型的数据，效果不明显
	int b = std::move(a);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
}

int main()
{
	/* test1(); */
	/* test2(); */
	/* test3(); */
	/* test4(); */	
	test5();
	return 0;
}
