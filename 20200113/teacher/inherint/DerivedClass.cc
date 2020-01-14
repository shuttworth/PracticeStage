 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base() {	cout << "Base()" << endl;	}

};

class Derived
: public Base
{
public:
	Derived(long derived)
	: _derived(derived)
	{
		cout << "Derived(long)" << endl;
	}

	void display() const
	{
		cout << "_derived:" << _derived << endl;
	}

private:
	long _derived;
};
 
int main(void)
{
	Derived d1(100);
	d1.display();

	return 0;
}
