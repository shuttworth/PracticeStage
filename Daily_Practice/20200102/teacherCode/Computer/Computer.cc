 ///
 /// @file    Computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-02 17:50:05
 ///
 
#include "Computer.h"
#include <iostream>
using std::cout;
using std::endl;
 
//在类之外定义成员函数
void Computer::setBrand(const char * brand)
{
	strcpy(_brand, brand);
}

#if 1
void Computer::setPrice(float price)
{
	_price = price;
}
#endif

void Computer::print()
{
	cout << "_brand:" << _brand << endl
		 << "_price:" << _price << endl;
}
