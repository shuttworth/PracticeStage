 ///
 /// @file    atexit.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-10 17:30:41
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void display()
{
	cout << "display()" << endl;
}
 
void show()
{
	cout << "show()" << endl;
}
int main(void)
{
	atexit(display);
	atexit(show);

	return 0;
}
