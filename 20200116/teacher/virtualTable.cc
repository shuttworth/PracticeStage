///
/// @file    virtualTable.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2020-01-16 09:57:45
///

#include <iostream>
using std::cout;
using std::endl;

class Base {
public:
	Base(long data1): _data1(data1) {}

	virtual 
		void func1() {	cout << "Base::func1()" << endl;	}
	virtual 
		void func2() {	cout << "Base::func2()" << endl;	}
	virtual 
		void func3() {	cout << "Base::func3()" << endl;	}
private:
	long _data1;
};

class Derived
: public Base {
public:
	Derived(long data1, long data2)
	: Base(data1)
	, _data2(data2) 
	{
		cout << "Derived(long,long)" << endl;
	}

	virtual void func1() {	cout << "Derived::func1()" << endl;	}
	virtual void func2() {	cout << "Derived::func2()" << endl;	}
private:
	long _data2;
};

int main(void)
{
	Derived d(1, 10);
	//long ** pvtable = (long **)&d;
	//long * table =*pvtable;
	
	long * p1 = (long *)&d;
	cout << "p1[0]: " << p1[0] << endl;//long
	cout << "p1[1]: " << p1[1] << endl;//long
	cout << "p1[2]: " << p1[2] << endl;//long
	
	long * pvtable = (long*)p1[0];
	cout << "pvtable[0]:" << pvtable[0] << endl;
	cout << "pvtable[1]:" << pvtable[1] << endl;
	cout << "pvtable[2]:" << pvtable[2] << endl;

	//函数类型
	typedef void(* Function)();
	Function f = (Function)pvtable[0];
	f();
	f = (Function)pvtable[1];
	f();
	f = (Function)pvtable[2];
	f();
	cout << endl;


	long ** pvtable2 = (long **)&d;
	Function f2 = (Function)pvtable2[0][0];
	f2();
	f2 = (Function)pvtable2[0][1];
	f2();
	f2 = (Function)pvtable2[0][2];
	f2();

	return 0;
}
