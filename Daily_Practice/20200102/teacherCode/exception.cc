///
/// @file    exception.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2020-01-02 11:19:52
///

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void test0()
{
	int number1, number2;
	cin >> number1 >> number2;
	int result;

	//try -catch会破坏代码风格，不建议大量使用
	try {
		if(number2 != 0) {
			result = number1 / number2;
			cout << "result : " << result << endl;
		} else 
			throw number2;
	} catch (int x){
		cout << "catch(int x), dividor cannot be zeor " << endl;

	} catch (double y) {
		cout << "catch(double y) " << endl;
	}
}

int main(void)
{
	test0();

}
