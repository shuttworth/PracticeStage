 ///
 /// @file    Complex.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-09 11:06:51
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Complex
{
	//复数
	//负数  -1 
public:
	Complex(double dreal, double dimage)
	: _dreal(dreal)
	, _dimage(dimage)
	{
		cout << "Complex(double,double)" << endl;
	}

	void print() const
	{
		cout << _dreal << " + " << _dimage << "i" << endl;
	}

	//重载形式之成员函数
	Complex operator+(const Complex & rhs)
	{
		cout << "Complex operator+(const Compelx &rhs)" << endl;
		return Complex(_dreal + rhs._dreal,
					   _dimage + rhs._dimage);
	}

private:
	double _dreal;
	double _dimage;
};

 
int main(void)
{
	int a = 1, b = 2;
	int c = a + b;

	Complex c1(1, 2), c2(3, 4);
	cout << "c1 = ";
	c1.print();
	cout << "c2 = ";
	c2.print();
	Complex c3 = c1 + c2;
	cout << "c3 = ";
	c3.print();
	


	return 0;
}
