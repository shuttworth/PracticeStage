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
	virtual
	void display() const 
	{
		cout << "Base::_base : " << _base << endl;
	}

	static Base getBase(long base) {
		//Base b(1);
		Base * pbase = new Base(base);
		//return b;
		return *pbase;
	}

private:
	//Base(const Base &);
	Base(long base = 0)
	: _base(base)
	{
		cout << "Base(long)" << endl;
	}

private:
	long _base;
};

#if 0
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

private:
	long _derived;
};
#endif

int test0()
{
	//Base base(1);//error

	Base b = Base::getBase(10);
	b.display();
	
	/* Derived d1(1, 10); */
	/* Base * pbase = &d1; */
	/* pbase->display(); */
	return 0;
}
 
int main(void)
{
	test0();
	return 0;
}
