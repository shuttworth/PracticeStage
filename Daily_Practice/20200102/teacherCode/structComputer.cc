 ///
 /// @file    Computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-02 17:23:54
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

struct Computer
{//类内部
//默认情况下全部是public
//public:
	//成员函数的声明
	void setBrand(const char * brand);
	void setPrice(float price);

	void print();

//private:
	char _brand[20];
	float _price;
};

//在类之外定义成员函数
void Computer::setBrand(const char * brand)
{
	strcpy(_brand, brand);
}

void Computer::setPrice(float price)
{
	_price = price;
}

void Computer::print()
{
	cout << "_brand:" << _brand << endl
		 << "_price:" << _price << endl;
}
 
int main(void)
{
	Computer com;
	com.setBrand("Macbook pro");
	com.setPrice(20000);
	com.print();

	return 0;
}
