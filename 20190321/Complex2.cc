#include <iostream>
#include <fstream>
#include <limits>
using std::cout;
using std::endl;
// i^2 = -1

class Complex
{
public:
	Complex(double dreal = 0, double dimag = 0)
	: _dreal(dreal)
	, _dimag(dimag)
	{	cout << "Complex(double,double)" << endl;	}

	void display() const 
	{
		if(_dreal != 0) {
			cout << _dreal ;
		} 
		if(_dimag > 0)
			cout << " + " << _dimag << "i" << endl;
		else if (_dimag <0) 
			cout << " - " << _dimag * (-1) << "i" << endl;
		else
			cout << _dimag <<  endl;
	}

	//复合赋值运算符推荐以成员函数形式进行重载
	//
	//表达式执行结束后，对象本身发生变化
	//
	Complex & operator+=(const Complex & rhs) {
		_dreal += rhs._dreal;
		_dimag += rhs._dimag;
		return *this;
	}

	//前置++
	//
	//前置的返回值是引用, 前置的执行效率高于后置
	//
	Complex & operator++() //前置
	{
		++_dreal;
		++_dimag;
		return *this;
	}

	//后置++
	//
	//后置的返回值是对象
	Complex operator++(int) // int作为一个标志位，以区别于前置 
	{
		Complex temp(*this);
		++_dreal;
		++_dimag;
		return temp;
	}

	friend Complex operator+(const Complex & lhs, const Complex & rhs);
	friend bool operator<(const Complex & lhs, const Complex & rhs);
	friend std::ostream & operator<<(std::ostream & os, const Complex & rhs);//输出流
	friend std::istream & operator>>(std::istream & is, Complex & rhs);//输入流

	//输出流运算符不能以成员函数形式进行重载，
	//因为其第一个参数是this指针, 与输出流运算符
	//对第一个参数的要求（左操作数是流对象）不符合，
#if 0
	std::ostream & operator<<(std::ostream & os)
	{
		os << _dreal << _dimag;
		return os;
	}
#endif
private:
	double _dreal;
	double _dimag;
};

//推荐用这一种方式重载
Complex operator+(const Complex & lhs, const Complex & rhs)
{
	return Complex(lhs._dreal + rhs._dreal, 
				   lhs._dimag + rhs._dimag);
}

#if 0
Complex operator+(const Complex & lhs, const Complex & rhs)
{
	Complex temp = lhs;
	temp += rhs;
	return temp;
}
#endif 

bool operator<(const Complex & lhs, const Complex & rhs)
{
	return lhs._dreal < rhs._dreal;
}

std::ostream & operator<<(std::ostream & os, const Complex & rhs)
{
	if(rhs._dreal != 0) {
		os << rhs._dreal;
	} 
	if(rhs._dimag > 0)
		os << " + " << rhs._dimag << "i";
	
	else if (rhs._dimag < 0) 
		os << " - " << rhs._dimag * (-1) << "i";
	else
		os << rhs._dimag;
	
	return os;
}

void readDoubleValue(std::istream & is, double & value) 
{
	while(is >> value, !is.eof()) {  //eof末尾
		if(is.bad()) {  //系统级别的故障，不可恢复
			cout << "istream has corrupted!" << endl;
			return;
		} else if(is.fail()) {  //可以恢复的故障
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "pls input a valid double value:" << endl;
			continue;
		}
		break;
	}
}
//对于输入流要考虑很多异常情况
std::istream & operator>>(std::istream & is, Complex & rhs)
{
	readDoubleValue(is, rhs._dreal);
	readDoubleValue(is, rhs._dimag);
	return is;
}

int test0(void)
{
	int a = 3, b = 4;
	a += b;// 执行完毕之后，a变化，b不变

	cout << "a = " << a << endl;
	cout << "++a =  " << ++a << endl;// 
	cout << "a = " << a << endl;
	
	cout << "a++ = " << a++ << endl;
	cout << "a = " << a << endl << endl;

	Complex c1(3, 4);
	cout << "c1 = ";
	c1.display();
	Complex c2(5, 6);
	cout << "c2 = ";
	c2.display();
	Complex c3 = c1 + c2;
	cout << "c3 = ";
	c3.display();
	cout << endl;

	cout << "++c3 = ";
	(++c3).display();
	cout << "c3 = ";
	c3.display();
	cout << endl;

	cout << "c3++ = ";
	(c3++).display();

	cout << "c3 = ";
	c3.display();

	return 0;
}

void test1()
{
	Complex c1(1, 1);
	cout << "c1 = " << c1 << endl;
	Complex c2(0, 0);
	cout << "c2 = " << c2 << endl;
	Complex c3(-1, -1);
	cout << "c3 = " << c3 << endl;
	Complex c4(0, -1);
	cout << "c4 = " << c4 << endl;
}

void test2()
{
	Complex c1(1, 1);
	Complex c2 = c1 + 5;//隐式转换
	cout << "c2 = ";
	c2.display();

	Complex c3 = 5 + c1;// operator+(Complex(5), c1);
	cout << "c3 = ";
	c3.display();
}

void test3()
{
	//std::ifstream ifs;
	//std::ifstream ifs2 = ifs;//流对象是不能进行复制的
	Complex c1(1, 2);
	//c1 << cout;
	cout << "c1 = " << c1 << endl;//输出流运算符重载
}

void test4()
{
	Complex c1;
	std::cin >> c1;
	cout << "c1 = " << c1 << endl;
}

int main(void)
{
	//test2();
	//test1();
	//test3();
	test4();
	return 0;
}
