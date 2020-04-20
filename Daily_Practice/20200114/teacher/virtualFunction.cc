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
	//构造函数为什么不能设置为虚函数?
	//virtual
	Base(long base)
	: _base(base)
	{
		cout << "Base(long)" << endl;
	}

	virtual 
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

	//当基类设置虚函数时，派生类重定义了该
	//函数，即使在其前面没有virtual关键字，
	//它也是虚函数
	void display() const
	{
		cout << "_derived: " << _derived << endl;
	}
#if 1
	virtual
	void display(int) const
	{
		cout << "_derived: " << _derived << endl;
	}
#endif

	//隐藏(oversee)
	void print() const
	{
		cout << "_derived: " << _derived << endl;
	}

private:
	long _derived;
};

class Derived2
: public Base
{
public:
	Derived2(long base, long derived)
	: Base(base)
	, _derived2(derived)
	{
		cout << "Derived(long,long)" << endl;
	}

	void display() const
	{
		cout << "_derived2: " << _derived2 << endl;
	}

	void print() const
	{
		cout << "_derived2: " << _derived2 << endl;
	}

private:
	long _derived2;
};

//1. 虚函数是如何实现的？
//当类中定义了一个虚函数时，会在对象的存储布局的
//开始位置，多一个虚函数指针，该虚函数指针指向了
//一个虚函数表(虚表), 虚表中存放的是虚函数的入口
//地址

//2. 什么叫覆盖(override)？
//当派生类重定义虚函数之后，就会将虚表中的同名
//虚函数的入口地址修改掉

//3. 运行时多态被激活的条件:
//
//1) 基类定义虚函数
//2) 派生类覆盖虚函数
//3) 创建派生类对象
//4) 基类指针或者引用指向派生类对象
//5) 基类指针或者引用调用虚函数

void display(Base & ref)
{
	ref.display();
}

void show(Base * base)
{
	base->display();//虚函数
}

void print(Base * base)
{
	base->print();//非虚函数
}
 
int test0(void)
{
	Base b1(100);
	Derived d1(1, 11);
	Derived2 d2(22, 222);
	//d1.display();
	
	cout << "sizeof(Base) : " << sizeof(Base) << endl
		 << "sizeof(Derived): " << sizeof(Derived) << endl;

	display(b1);
	display(d1);
	display(d2);
	cout << endl;

	show(&b1);
	show(&d1);
	show(&d2);
	cout << endl;

	print(&b1);
	print(&d1);
	print(&d2);

	return 0;
}

void test1()
{
	Derived d(1, 11);
	d.print();//隐藏机制, 在基类与派生类之间，函数名相同
	//d.print(1);//error  派生类中根本看不到基类的同名函数
	d.Base::print();

	d.display();//通过对象名调用虚函数，不会表现多态特性
				//这里发生的是隐藏
}

int main()
{
	test1();
	return 0;
}
