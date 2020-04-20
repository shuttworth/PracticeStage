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

	//表达式执行完毕之后，左操作数发生变化的情况，
	//以成员函数形式重载
	Complex & operator+=(const Complex & rhs)
	{
		cout << "Complex operator+=() " << endl;
		_dreal += rhs._dreal;
		_dimage += rhs._dimage;

		return *this;
	}

	//前置形式, 其效率更高
	Complex & operator++()
	{
		++_dreal;
		++_dimage;
		return *this;
	}

	//后置形式
	Complex operator++(int) //int并不是要传递参数，仅仅只是一个标志符
	{
		Complex tmp(*this);//局部对象
		++_dreal;
		++_dimage;
		return tmp;
	}

	//friend Complex operator+(const Complex & lhs, const Complex & rhs);


private:
//public:
	double _dreal;
	double _dimage;
};

//友元函数形式重载
#if 0
Complex operator+(const Complex & lhs, const Complex & rhs)
{
	cout << "Complex operator+(lhs,rhs)" << endl;
	return Complex(lhs._dreal + rhs._dreal,
				   lhs._dimage + rhs._dimage);
}
#endif

Complex operator+(const Complex & lhs, const Complex & rhs)
{
	Complex tmp(lhs);//调用拷贝构造函数
	tmp += rhs;// tmp.operator+=(rhs);
	return tmp;
}

// += -= *=
 
int test0(void)
{
	cout << ">> test0:" << endl;
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

void test1()
{
	cout << ">> test1:" << endl;
	int a = 1, b = 2;
	a += b; // a =  a + b

	Complex c1(1, 2), c2(3, 4);
	cout << "c1 = ";
	c1.print();
	cout << "c2 = ";
	c2.print();
	c1 += c2;
	cout << "c1 = ";
	c1.print();

}

void test2()
{
	int a = 1;
	//后置形式: 表达式本身返回的是a变化之前的值；
	//	  该表达式执行结束之后，a的值是加1了
	cout << "a++: " << (a++) << endl;
	cout << "a: " << a << endl;
	//&(a++);//error, 返回的是一个临时变量(右值),不能取地址


	//前置形式: 表达式本身返回的是a变化之后的值；
	//	  该表达式执行结束之后，a的值是加1了
	&(++a);//ok, 可以取地址(左值)
	cout << "++a: " << (++a) << endl;
	cout << "a: " << a << endl;
	cout << endl;

	Complex c1(10, 11);
	cout << "c1++: "; 
	(c1++).print();
	cout << "c1 = ";
	c1.print();

	cout << endl;
	cout << "++c1:";
	(++c1).print();
	cout << "c1 = ";
	c1.print();

}


int main()
{
	//test0();
	//test1();
	test2();
	return 0;
}
