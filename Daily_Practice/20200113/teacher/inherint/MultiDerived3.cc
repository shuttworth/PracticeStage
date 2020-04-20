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
	A(): _number(0) {	cout << "A()" << endl;}
	A(long number): _number(number) {	cout << "A(long)" << endl;}

	void print() const {	cout << "A::print(): _number: " << _number << endl;	}
	void setNumber(long number) 
	{	_number = number;	}


protected:
	long _number;
};
 
class B
: virtual public A
{
public:
	//void print() const {	cout << "B::print()" << endl;	}
	void printB() const {	cout << "B::print() _number: " << _number << endl;	}
};

class C
: virtual public A
{
public:
	void printC() const {	cout << "C::print() _number: " << _number << endl;	}
	//void print() const {	cout << "C::print()" << endl;	}
};

class D
: public B
, public C
{
public:
	void printD() const {	cout << "D::print() _number: " << _number << endl;	}
};

int main(void)
{
	D d;
	//问题2: 多重继承时，存储二义性的问题
	//解决方案：虚拟继承
	d.setNumber(100);//error
	//d.A::setNumber(100);//error
	//
	//
	//d.B::setNumber(100);
	//d.C::setNumber(101);

	cout << "sizeof(long) = " << sizeof(long) << endl;
	cout << "sizeof(D) = " << sizeof(D) << endl;
	//d对象的存储布局之中，有2份A的拷贝
	
	d.print();
	d.printB();
	d.printC();
	d.printD();

	return 0;
}
