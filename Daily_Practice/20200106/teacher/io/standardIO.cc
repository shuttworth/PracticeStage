#include <iostream>
#include <string>
#include <limits>
using std::cout;
using std::cin;
using std::endl;
using std::string;

void printStreamState()
{
	cout << "cin.badbit : " << cin.bad() << endl;
	cout << "cin.failbit: " << cin.fail() << endl;
	cout << "cin.eofbit: " << cin.eof() << endl;
	cout << "cin.goodbit: " << cin.good() << endl;
}
 
int main(void)
{

	int number = 0;
	printStreamState();
	
	cin >> number;

	printStreamState();
 
	cout << "number = " << number << endl;

	cin.clear();//重置流的状态
	//cin.ignore(1024, '\n');// 清空缓冲区
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// 清空缓冲区
	cout << endl;
	printStreamState();

	cout << endl;
	string line;
	cin >> line;//正常进行工作的前提条件: 流是有效的
	cout << "line: " << line << endl;

	return 0;
}
