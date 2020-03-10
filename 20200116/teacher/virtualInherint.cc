///
/// @file    virtualInherint.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2020-01-16 15:02:08
///

#include <iostream>
using std::cout;
using std::endl;

class A {
public:
	A() {	cout << "A()" << endl;	}

	A(int ia)
	: _ia(ia) 
	{	cout << "A(int)" << endl;	}

	void f() {	cout << "A::f()" << endl;	}
protected:
	int _ia;
};

class B
: virtual public A {
public:
	B() {	cout << "B()" << endl;	}

	B(int ia, int ib)
	: A(ia)
	, _ib(ib)
	{	cout << "B(int,int)" << endl;	}

protected:
	int _ib;
};

class C
: public B {
public:
	//虚拟继承时，必须要在继承体系的每一层中显式调用虚基类的相应构造函数
	//如果没有显式调用，就会调用虚基类的默认构造函数
	C(int ia, int ib, int ic)
	: B(ia, ib)
	, A(ia)  
	, _ic(ic) 
	{	
		cout << "C(int,int,int)" << endl;	
	}

	void show() const 
	{
		cout << "_ia: " << _ia << endl
			 << "_ib: " << _ib << endl
			 << "_ic: " << _ic << endl;
	}
private:
	int _ic;
};

int main(void)
{
	C c(1, 2, 3);
	c.show();

	return 0;
}
