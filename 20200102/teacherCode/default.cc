///
/// @file    default.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2020-01-02 10:13:49
///

#include <iostream>
using std::cout;
using std::endl;

#if 0
int add(int x, int y)
{
	return x + y;
}
#endif

//一旦某一个参数被设置为默认参数，
//其后的所有参数都要设置默认参数
int add(int x = 0, int y = 0, int z = 0)
{
	return x + y + z;
}

int  main(void)
{
	int a = 1, b = 2, c = 3;
	cout << "add() = " << add() << endl;
	cout << "add(a) = " << add(a) << endl;
	cout << "add(a, b) = " << add(a, b) << endl;
	//cout << "add(,1,2) " <<  add(,1,2) << endl;
	//cout << "add(a, b, c) = " << add(, b, c) << endl;
	return 0;
}
