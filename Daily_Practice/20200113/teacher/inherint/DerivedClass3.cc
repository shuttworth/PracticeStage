 ///
 /// @file    DerivedClass.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-13 15:22:47
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Foo
{
public:
	Foo(int foo) : _foo(foo){cout << "Foo(int)" << endl;	}
	~Foo() {	cout << "~Foo()" << endl;	}

	void print() const 
	{	cout << "_foo: " << _foo << endl;	}	
private:
	int _foo;

};

class Base
{
public:

	Base() {	cout << "Base()" << endl;}

	Base(long base)
	: _base(base)
	{	cout << "Base(long)" << endl;	}

	void print() const
	{	cout << "_base: " << _base << endl;}

	~Base() {	cout << "~Base()" << endl;	}

//private:
protected:
	long _base;
};

//
//
//错误说法: 在创建派生类对象时，
//	 先调用基类构造函数，再调用派生类构造函数
//
//创建派生类对象时，要先初始化基类部分
//再初始化派生类部分
//
//说法: 在创建派生类对象时，先调用派生类构造函数,
//在执行派生类构造函数的过程中，调用了基类的构造函数
//完成基类部分的初始化，之后再完成派生类部分的初始化
class Derived
: public Base
{
public:
#if 1
	Derived(long derived)
	: Base()
	, _derived(derived)
	, _foo(0)
	{
		cout << "Derived(long)" << endl;
	}
#endif

	Derived(long base, long derived)
	//: _base(base) //error
	: Base(base) //显式调用基类有参构造函数
	, _derived(derived)
	, _foo(100)
	{
		cout << "Derived(long,long)" << endl;
	}

	void display() const
	{
		cout << "_derived:" << _derived << endl;
		//_base1.print();
	}

	//当派生类对象被销毁时，先调用派生类析构函数，
	//之后再自动基类的析构函数
	~Derived() {	cout << "~Derived()" << endl;}

private:
	long _derived;
	//Base _base1;
	Foo _foo;
};
 
int main(void)
{
	Derived d1(1, 10);
	d1.display();

	return 0;
}
