#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

void test()
{
	int number = 0;

	cout << "pls input a valid integer:\n";
	//逗号表达式
	//标准输入流， 按ctrl + d 结束输入
	//ctrl + c ,  通过信号终止程序
	//
	//ctrl + z ,  将当前任务在后台挂起
	//
	while(cin >> number, !cin.eof())
	{
		if(cin.bad()) {
			cerr << "stream has corupted! \n";
			return;
		}

		if(cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "pls input a valid integer:\n";
			continue;
		}

		cout << "number = " << number << endl;
	}

}
 
int main(void)
{
	test();
	return 0;
}
