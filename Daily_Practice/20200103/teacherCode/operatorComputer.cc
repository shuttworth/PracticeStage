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
	Computer(const char * brand, float price)
	//: _brand(brand) //浅拷贝
	: _brand(new char[strlen(brand) + 1]())
	, _price(price)
	{
		cout << "Computer(const char *, float)" << endl;
		strcpy(_brand, brand);//深拷贝
	}

#if 0
	//默认的拷贝构造函数不再满足当前的需求
	//必须显式提供
	Computer(const Computer & rhs)
	: _brand(rhs._brand) //浅拷贝
	, _price(rhs._price)
	{
	
	}
#endif

	Computer(const Computer & rhs)
	: _brand(new char[strlen(rhs._brand) + 1]())
	, _price(rhs._price)
	{
		cout << "Computer(const Computer &)" << endl;
		strcpy(_brand, rhs._brand);
	}

	//系统提供的赋值运算符函数不再满足需求，
	//所以必须显式定义赋值运算符函数
#if 0
	Computer & operator=(const Computer & rhs)
	{
		cout << "Computer & operator=()" << endl;
		_brand = rhs._brand;
		_price = rhs._price;
		return *this;
	}
#endif
	//重难点: 最容易犯错
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
		printf("&_brand: %p\n", _brand);
		cout << "brand:" << _brand << endl
			 << "price:" << _price << endl;
	}

	~Computer()
	{
		delete [] _brand;
		cout << "~Computer()" << endl;
	}

private:
	char * _brand;// 8    字节对齐
	float _price;//  4
};


void test0()
{
	Computer pc1("Macbook pro", 20000);
	Computer pc2("Thinkpad", 8888);

	cout << "pc1: ";
	pc1.print();
	cout << "pc2: ";
	pc2.print();

	cout << endl;
	pc1 = pc2;
	cout << "pc1: ";
	pc1.print();


	pc1 = pc1;//自复制
}

int main(void)
{
	test0();
	return 0;
}
