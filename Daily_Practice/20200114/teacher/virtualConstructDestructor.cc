///
/// @file    virtualConstructDestructor.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2020-01-14 16:28:47
///

#include <iostream>
using std::cout;
using std::endl;

class Grandpa {
public:
	Grandpa() {	cout << "Grandpa()" << endl;	}
	~Grandpa() {	cout << "~Grandpa()" << endl;	}

	virtual 
	void func1() {	cout << "Grandpa::func1()" << endl;	}
	virtual 
	void func2() {	cout << "Grandpa::func2()" << endl;	}
};

class Father
: public Grandpa {
public:
	//在调用构造函数或者析构函数的过程中，
	//调用虚函数时，并不表现动态多态特性，
	//只会表现静态联编
	Father() {	
		cout << "Father()" << endl;	
		func1();//静态联编  
	}	
	~Father() {	
		cout << "~Father()" << endl;	
		func2();//静态联编
	}

#if 0
	virtual 
	void func1() {	cout << "Father::func1()" << endl;	}
	virtual 
	void func2() {	cout << "Father::func2()" << endl;	}
#endif
};

class Son
: public Father {
public:
	Son() {	cout << "Son()" << endl;	}	
	~Son() {	cout << "~Son()" << endl;	}

	virtual void func1() {	cout << "Son::func1()" << endl;	}
	virtual void func2() {	cout << "Son::func2()" << endl;	}
};

int main(void)
{
	Son son;

	return 0;
}
