 ///
 /// @file    Computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-02 17:23:54
 ///
 
#ifndef __COMPUTER_H__
#define __COMPUTER_H__ 

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{//类内部
//在类内部定义的函数全部是inline函数
public:
	//inline
	void setBrand(const char * brand)
	{
		strcpy(_brand, brand);
	}

	//inline
	void setPrice(float price)
	{
		_price = price;
	}

	//inline
	void print()
	{
		cout << "_brand:" << _brand << endl
			 << "_price:" << _price << endl;
	}

private:
	char _brand[20];
	float _price;
};

#endif
