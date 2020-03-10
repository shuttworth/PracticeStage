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
	Base(long base, long data)
	: _base(base)
	, _data(data)
	{
		cout << "Base(long,long)" << endl;
	}

	//即使加上inline关键字，也不会内联
	//inline关键字不起作用
	inline virtual 
	void display() const
	{
		cout << "_base: " << _base << endl;
	}
	
	//函数重载:在同一个类内部 
	void print() 
	{
		cout << "_base: " << _base << endl;
	}

	void print() const
	{
		cout << "_base: " << _base << endl;
	}

	void print(int) const
	{
		cout << "_base: " << _base << endl;
	}
private:
	long _base;
protected:
	long _data;
};

class Derived
: public Base
{
public:
	Derived(long base, long data1, long derived, long data2)
	: Base(base, data1)
	, _derived(derived)
	, _data(data2)
	{
		cout << "Derived(long,long)" << endl;
	}

	virtual
	void display() const override
	{
		cout << "_derived: " << _derived << endl;
	}

	//隐藏(oversee)
	void print() const
	{
		cout << "_derived: " << _derived << endl;
		//直接使用，只能访问到派生类中的_data
		//发生了隐藏
		cout << "_data: " << _data << endl;
		cout << "Base::_data : " << Base::_data << endl;
	}

private:
	long _derived;
	long _data;
};

void test0()
{
	Derived d(1, 2, 3, 4);
	d.print();
	d.Base::print();
	cout << endl;

	Base * pbase = &d;
	pbase->display();

	cout << endl;
	pbase->Base::display();
}

int main(void)
{
	test0();
	return 0;
}

