 ///
 /// @file    virtualFunction.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-14 14:33:33
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base(long base)
	: _base(base)
	{
		cout << "Base(long)" << endl;
	}

	virtual 
	void display() const
	{
		cout << "Base::display " << endl;
	}

	virtual
	void print() const
	{
		cout << "Base::print() " << endl;
	}

	virtual
	void show() const
	{	cout << "Base::show()" << endl;}

private:
	long _base;
};

class Derived
: public Base
{
public:
	Derived(long base, long derived)
	: Base(base)
	, _derived(derived)
	{
		cout << "Derived(long,long)" << endl;
	}

	virtual
	void print() const
	{
		cout << "Derived::print() " << endl;
	}

	virtual
	void show() const
	{	cout << "Derived::show()" << endl;}

	virtual
	void display() const
	{
		cout << "Derived::display() " << endl;
	}


private:
	long _derived;
};

void test0()
{
	Derived d(1, 11);
	Base * pbase = &d;

	pbase->display();
	pbase->show();
	pbase->print();
}

int main(void)
{
	test0();

	return 0;
}
