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
	void display(int idx = 0) const
	{
		cout << "Base::display, idx = " << idx << endl;
	}

	void func1()
	{
		this->display();//展现动态多态特性
	}

	void func2()
	{
		Base::display();//没有多态特性
	}

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
	void display(int idx = 1) const
	{
		cout << "Derived::display(),idx = " << idx << endl;
	}



private:
	long _derived;
};

void test0()
{
	Base base(1);
	base.func1();
	base.func2();

	Derived derived(11, 12);

	Base * pbase = &derived;
	pbase->func1();
	pbase->func2();
}

int main(void)
{
	test0();
	return 0;
}
