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
	Base() {	cout << "Base()" << endl;	}

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

//当派生类有显式定义复制控制函数时，执行派生类
//对象间的复制控制操作时，是不会再自动调用
//基类的相应复制控制函数，必须手动显式调用;
//否则复制控制操作就是不完整的

class Derived
: public Base
{
public:
	Derived(const char * data, const char * data2)
	: Base(data)
	, _data2(new char[strlen(data2) + 1]())
	{	
		cout << "Derived(const char *, const char *)" << endl;	
		strcpy(_data2, data2);
	}

	Derived(const Derived & rhs)
	: Base(rhs) //const Base & r = rhs;
	, _data2(new char[strlen(rhs._data2) + 1]())
	{
		cout << "Derived(const Derived &)" << endl;
		strcpy(_data2, rhs._data2);
	}

	Derived & operator=(const Derived & rhs)
	{
		if(this != & rhs) {
			Base::operator=(rhs);//显式调用赋值运算符函数
			delete [] _data2;

			_data2 = new char[strlen(rhs._data2) + 1]();
			strcpy(_data2, rhs._data2);
		}
		cout << "Derived & operator=(const Derived&)" << endl;
		return *this;
	}

	~Derived()
	{	cout << "~Derived()" << endl;	}	

	friend std::ostream & operator<<(std::ostream & os, const Derived & rhs);
private:
	char * _data2;
};

std::ostream & operator<<(std::ostream & os, const Derived & rhs)
{
	os << rhs.data() << "," << rhs._data2;
	return os;
}

int main(void)
{
	Derived d("hello", "world");

	cout << "d: " << d << endl;

	Derived d2 = d;//拷贝构造函数
	cout << "d2:" << d2 << endl;
	cout << endl;

	Derived d3("wuhan", "wangdao");
	cout << "d3: " << d3 << endl;
	d3 = d;//Derived的赋值运算符函数
	cout << "d3: " << d3 << endl;
	

	return 0;
}
