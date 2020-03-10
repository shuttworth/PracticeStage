 ///
 /// @file    pureFunction.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-14 16:39:23
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	//纯虚函数没有实现
	//拥有纯虚函数的类称为抽象类, 不能创建对象
	//
	//提供统一的接口
	virtual void display()=0;
	virtual void print()=0;
	//void print();
};

class B
: public A
{
public:
	//派生类一定要实现所有的纯虚函数，才能创建对象；
	//否则它自己成为抽象类
	void display() {	cout << "B::display()" << endl;}
};

class C
: public B
{
public:
	void print()
	{	cout << "C::print()" << endl;	}
};
 
int main(void)
{
	//A a;//error
	//a.print();
	//B b;//error
	C c;
	A * pa = &c;
	pa->print();
	pa->display();

	return 0;
}
