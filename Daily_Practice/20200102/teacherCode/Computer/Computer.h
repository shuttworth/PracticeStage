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
public:
	void setBrand(const char * brand);
	void setPrice(float price);

	void print();

private:
	char _brand[20];
	float _price;
};

#endif
 
