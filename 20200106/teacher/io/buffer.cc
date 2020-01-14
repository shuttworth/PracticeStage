 
#include <unistd.h>

#include <iostream>
using std::cout;
using std::endl;
using std::ends;
using std::flush;

void test()
{
	for(size_t idx = 0; idx < 1024; ++idx) {
		cout << 'a';
	}
	//cout << "123" << endl;
	cout << endl;//printf()效率高于cout
	//cout.operator<<(endl);
	//链式编程
	//cout << "123" << ends;
//	cout << "123" << flush;

	//int number1, number2, number3;
//	std::cin >> number1 >> number2 >> number3;
	sleep(3);
}
 
int main(void)
{
	test();
 
	return 0;
}
