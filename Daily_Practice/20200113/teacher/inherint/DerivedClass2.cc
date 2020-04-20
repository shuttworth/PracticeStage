 ///
 /// @file    DerivedClass.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-13 15:22:47
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:

	Base() {	cout << "Base()" << endl;}

	Base(long base)
	: _base(base)
	{	cout << "Base(long)" << endl;	}

private:
	long _base;
};

class Derived
: public Base
{
public:
#if 0
	Derived(long derived)
	: _derived(derived)
	{
		cout << "Derived(long)" << endl;
	}
#endif

	void display() const
	{
		cout << "_derived:" << _derived << endl;
	}

private:
	long _derived;
};
 
int main(void)
{
	Derived d1;
	d1.display();

	return 0;
}
