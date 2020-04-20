///
/// @file    typecast.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2020-01-14 10:19:39
///

#include <iostream>
using std::cout;
using std::endl;

class Base {
public:
	Base(long base)
	: _base(base)
	{	cout << "Base(long)" << endl;	}

	void print() const
	{
		cout << "_base : " << _base << endl;
	}
private:
	long _base;
};

class Derived
: public Base {
public:
	Derived(long base, long derived)
	: Base(base)
	, _derived(derived)
	{	cout << "Derived(long,long)" << endl;	}

	void display() const
	{
		cout << "_derived: " << _derived << endl;
	}

private:
	//long _derived;
};

void display(Base * base)
//void display(Base & base)
{
	base->print();
}

void display2(Derived & d)
{
	d.print();
	d.display();
}

int main(void)
{
	Base base(1);
	Derived derived(10, 20);

	display(&base);
	display(&derived);
	cout << endl;

	display2(derived);
	//display2(base);//error  
	Derived & d = base;//error
	d.display();

	Derived * pd = &base;//error
	char * p1 = "hello";
	pd++;
	p1++;

	//Drerived(const Derived &rhs)
	//const Derived & rhs = base;
	Derived d2 = base;//error

	//Base(const Base &)
	//可以将一个派生类对象赋值给基类对象
	Base b1 = derived;//const Base &rhs = derived

	//可以用一个基类的指针指向派生类对象
	Base * p2 = &derived;//向上转型

	//可以用一个基类的引用绑定到派生类对象
	Base & ref = derived;


	
	cout << "sizeof(Derived) : " << sizeof(Derived) << endl;


	return 0;
}
