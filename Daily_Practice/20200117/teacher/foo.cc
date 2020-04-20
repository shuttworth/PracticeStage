 ///
 /// @file    foo.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-17 09:43:13
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//要表现动态多态
class A
{
public:


	virtual
	void display() const
	{	cout << "A::display()" << endl;}

	virtual
	~A() {	cout << "~A()" << endl;	}

protected:
	A() {	cout << "A()" << endl;}
};

class B
: public A
{
public:
	B(): A() {	cout << "B()" << endl;} 

	void display() const
	{	cout << "B::display()" << endl;}

	~B() {	cout << "~B()" << endl;}
};
 
int main(void)
{
	A a;

	A * pa = new B();
	pa->display();

	delete pa;

	return 0;
}
