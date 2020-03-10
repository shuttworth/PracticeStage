///
/// @file    multiDerivedVirtual.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2020-01-15 11:29:21
///

#include <iostream>
using std::cout;
using std::endl;

class A {
public:
	virtual void a() {	cout << "a() in A" << endl;	}
	virtual void b() {	cout << "b() in A" << endl;	}
	virtual void c() {	cout << "c() in A" << endl;	}
};

class B {
public:
	virtual void a() {	cout << "a() in B" << endl;	}
	virtual void b() {	cout << "b() in B" << endl;	}
	void c() {	cout << "c() in B" << endl;	}
	void d() {	cout << "d() in B" << endl;	}
};

class C
: public A
, public B {
public:
	virtual void a() {	cout << "a() in C" << endl;	}
	void c() {	cout << "c() in C" << endl;	}
	void d() {	cout << "d() in C" << endl;	}
};

class D
: public C
{
public:
	void c() {	cout << "c() in D" << endl;	}	
};

int main(void)
{
	C c;

	A * pa = &c;
	pa->a();//虚函数调用
	pa->b();//虚函数调用
	pa->c();//虚函数调用

	cout << endl;

	B * pb = &c;
	pb->a();//虚函数调用
	pb->b();//虚函数调用
	pb->c();//非虚函数
	pb->d();//非虚函数
	cout << endl;

	C * pc = &c;
	pc->a();
	//pc->b();//二义性
	pc->A::b();
	pc->B::b();
	pc->c();//虚函数
	pc->d();

	cout << "sizeof(A) = " << sizeof(A) << endl
		 << "sizeof(B) = " << sizeof(B) << endl
		 << "sizeof(C) = " << sizeof(C) << endl;

	cout << "pa = " << pa << endl
		 << "pb = " << pb << endl
		 << "pc = " << pc << endl;

	D d;
	C * pc2 = &d;
	pc2->c();

	return 0;
}
