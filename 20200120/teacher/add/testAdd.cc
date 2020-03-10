 ///
 /// @file    testAdd.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-20 10:07:01
 ///
 
#include "add.hh" // C++的头文件 .hpp .hh
//#include "add.h" // C的头文件

#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	int x1 = 1, x2 = 2;
	cout << "add(x1, x2): " << add(x1, x2) << endl;

	return 0;
}
