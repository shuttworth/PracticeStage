 ///
 /// @file    Computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-03 10:59:46
 ///
 
#include <string.h>

#include <iostream>
using std::cout;
using std::endl;


class Computer
{
public:
	Computer(const char * brand, double price)
	//: _brand(brand) //浅拷贝
	: _brand(new char[strlen(brand) + 1]())
	, _price(price)
	{
		cout << "Computer(const char *, float)" << endl;
		strcpy(_brand, brand);//深拷贝
	}

	void setTotalPrice()
	{
		_totalPrice += _price;
	}


	Computer(const Computer & rhs)
	: _brand(new char[strlen(rhs._brand) + 1]())
	, _price(rhs._price)
	{
		cout << "Computer(const Computer &)" << endl;
		strcpy(_brand, rhs._brand);
	}

	Computer & operator=(const Computer & rhs)
	{
		cout << "Computer & operator=()" << endl;
		if(this != &rhs) {// 自复制
			//回收原来的堆空间
			delete [] _brand;

			_brand = new char[strlen(rhs._brand) + 1]();
			strcpy(_brand, rhs._brand);//深拷贝
			
			_price = rhs._price;
		}
		return *this;
	}

	void print()
	{
		cout << "brand:" << _brand << endl
			 << "price:" << _price << endl << "total price: " << _totalPrice << endl;
	}

	~Computer()
	{
		delete [] _brand;
		cout << "~Computer()" << endl;
	}

private:
	char * _brand;
	double _price;

	//被该类的所有对象共享的成员
	//位于全局静态区, 不会占据对象的空间
	static double _totalPrice;
};

//静态成员必须要在类之外进行初始化
double Computer::_totalPrice = 0.0;

void test0()
{
	cout << "sizeof(Computer) : " << sizeof(Computer) << endl;
	Computer pc1("Macbook pro", 20000);
	cout << "pc1: ";
	pc1.print();

	Computer pc2("Thinkpad", 8888);
	cout << "pc2: ";
	pc2.print();


}

int main(void)
{
	test0();
	return 0;
}
