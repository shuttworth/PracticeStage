 ///
 /// @file    MultiDerived2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-13 16:29:21
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	void print() const {	cout << "A::print()" << endl;	}
};
 
class B
{
public:
	void print() const {	cout << "B::print()" << endl;	}
};
class C
{
public:
	void print() const {	cout << "C::print()" << endl;	}
};
class D
: public A
, public B
, public C
{};

int main(void)
{
	D d;
	//问题1: 多重继承时，成员名访问冲突的二义性
	//解决方案：直接使用作用域限定符
	//d.print();//error
	d.A::print();
	d.B::print();
	d.C::print();

	return 0;
}
