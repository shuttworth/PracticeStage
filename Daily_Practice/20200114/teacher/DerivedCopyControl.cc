///
/// @file    DerivedCopyControl.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2020-01-14 11:11:34
///

#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class Base {
public:
	Base(const char * data)
	: _data(new char[strlen(data) + 1]())
	{	
		cout << "Base(const char * data)" << endl;	
		strcpy(_data, data);
	}

	Base(const Base & rhs)
	: _data(new char[strlen(rhs._data) + 1]())
	{
		strcpy(_data, rhs._data);
		cout << "Base(const Base & )" << endl;
	}

	Base & operator=(const Base & rhs)
	{
		cout << "Base & operator=(const Base &)" << endl;
		if(this != &rhs) {
			delete [] _data;

			_data = new char[strlen(rhs._data) + 1]();
			strcpy(_data, rhs._data);
		}
		return *this;
	}

	~Base()
	{
		cout << "~Base()" << endl;
		delete [] _data;
	}

	const char * data() const
	{	return _data;	}

protected:
	char * _data;
};

//当派生类没有显式定义复制控制函数时，会自动调用
//基类的相应复制控制函数
class Derived
: public Base
{
public:
	//对于基类的非私有成员，派生类不能直接初始化
	//只能调用基类构造函数完成基类成员初始化
	Derived(const char * data1)
	//: _data(new char[strlen(data1) + 1]()) //error
	: Base(data1)
	{
		cout << "Derived(const char*)" << endl;
	}

#if 0
	Derived(const Derived&)
	{
		cout << ""
	}
#endif

	void display() const
	{	cout << "Derived::display()" << endl;}

	~Derived() {	cout << "~Derived()" << endl;	}
};

int main(void)
{
	Derived d("hello");
	d.display();
	cout << endl;

	Derived d2 = d;//拷贝构造函数
	d2.display();
	cout << endl;

	Derived d3("world");
	d3 = d;//Derived的赋值运算符函数

	return 0;
}
