 ///
 /// @file    protectedConstructor.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-15 10:52:53
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base(long base = 0)
	: _base(base)
	{
		cout << "Base(long)" << endl;
	}

	//规定: 只要类中出现了一个虚函数，都需要将
	//析构函数设置为虚函数
	virtual
	void display() const 
	{
		cout << "Base::_base : " << _base << endl;
	}

	virtual
	~Base()  // 只有一个
	{
		cout << "~Base()" << endl;
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

	void display() const 
	{
		cout << "_derived: " << _derived << endl;
	}

	//当基类的析构函数设置为虚函数之后，
	//派生类的析构函数会自动成为虚函数
	~Derived() {	cout << "~Derived() " << endl;}

private:
	long _derived;
};

int test0()
{
	//Base base(1);//error
	
	Derived d1(1, 10);
	Base * pbase = &d1;
	pbase->display();
	return 0;
}

void test1()
{
	Base * pbase = new Derived(1, 10);
	pbase->display();
	delete pbase;//发生了内存泄漏
}
 
int main(void)
{
	/* test0(); */
	test1();
	return 0;
}
