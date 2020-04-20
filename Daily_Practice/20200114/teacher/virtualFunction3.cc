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
	void display(int idx =0) const
	{
		cout << "Base::display, idx = " << idx << endl;
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
	void display(int idx = 1) const
	{
		cout << "Derived::display(),idx = " << idx << endl;
	}

	virtual
	void print() const
	{
		cout << "Derived::print() " << endl;
	}

	virtual
	void show() const
	{	cout << "Derived::show()" << endl;}



private:
	long _derived;
};

void test0(Base * base)
{
	//虽然运行时会调用派生类虚函数
	//但对于传递的默认参数的值，只与指针的类型有关
	base->display();
}

int main(void)
{
	Derived d(1, 11);
	test0(&d);

	return 0;
}
