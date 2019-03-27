#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

void func()
{
	cout << "func()" << endl;
}
 
//atexit的作用：当程序正常退出时，会自动调用其注册的函数，注册几次就调用几次
int main(void)
{
	cout << "enter main()" << endl;
	atexit(func);
	atexit(func);

	cout << "after main()" << endl;
	return 0;
}
