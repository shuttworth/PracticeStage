 ///
 /// @file    scope.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-10 16:02:44
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int number = 1;

class Point;


namespace wd
{
int number = 2;


class Example
{
public:
	void print(int number) {
		cout << "形参number:" << number << endl;
		cout << "类中的number:" << this->number << endl
			 << "类中的number:" << Example::number << endl
			 << "wd空间中的number:" << wd::number << endl
			 << "全局变量number:" << ::number << endl;
	}
	
private:
	int number = 3;

};

}// wd

 
int main(void)
{
	int num = 10;
	wd::Example e;
	e.print(num);

	return 0;
}
