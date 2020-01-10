 ///
 /// @file    TestComputer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-02 17:57:56
 ///
 
#include "Computer.h"
#include <iostream>
using std::cout;
using std::endl;


void test();
 
int main(void)
{
	Computer com;
	com.setBrand("Macbook pro");
	com.setPrice(20000);
	com.print();

	test();

	return 0;
}
