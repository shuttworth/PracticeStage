 ///
 /// @file    TestComputer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-02 17:51:25
 ///
 
#include "Computer.h"
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	Computer com;
	com.setBrand("Macbook pro");
	com.setPrice(20000);
	com.print();

	return 0;
}
