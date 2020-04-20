#include <iostream>
using std::cout;
using std::endl;

class Test
{
public:
	int operator()(int x, int y) {  // 对()重定义
		return x + y;
	}

	int operator()(int x, int y, int z) {
		return x * y * z;
	}
private:
	int _cnt;
};

int func1(int x, int y)
{
	static int c = 0;
	++c;
	return x + y;
}
 
int main(void)
{
	Test test;//函数对象携带了状态的  --> 闭包 --> lambda表达式 --> 匿名函数
	cout << "test(3, 4) = " << test(3, 4) << endl;//重载了函数运算符的类创建的对象称为函数对象
	cout << "test(3, 4, 5) = " << test(3, 4, 5) << endl;
	cout << "func1(3, 4) = " << func1(3, 4) << endl;
	//Test test2;

	return 0;
}
