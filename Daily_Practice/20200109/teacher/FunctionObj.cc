 ///
 /// @file    FunctionObj.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-09 14:59:40
 ///
 
#include <iostream>
using std::cout;
using std::endl;

struct Foo
{
	Foo() = default;

	//函数调用运算符
	int operator()(int x, int y)
	{
		++_count;
		return x + y;
	}

	int operator()(int x, int y, int z)
	{
		return x * y * z;
	}

	int count() const {	return _count;	}
private:
	int _count = 0;//函数的状态
};


//无记忆性
void func()
{
	int x = 1;
	cout << "x = " << x <<  endl;
}
 
void test0()
{
	Foo c1;//对象
	int a = 1, b = 2, c = 3;

	//函数对象： 重载了函数调用运算符的类创建的对象
	//			 携带了状态的函数
	//函数闭包 ==> lambda表达式 ==> 匿名函数
	cout << "c1(a, b) : " << c1(a,b) << endl;
	cout << "c1(a, b, c): " << c1(a, b, c) << endl;

	cout << "c1.count(): " << c1.count() << endl;
	
	func();

	//自动推导类型
	//auto f = [=](int x){	//通过值传递方式捕获上下文信息
	auto f = [&](int x){//通过引用传递方式捕获上下文信息
		int m = a;
		int n = b;
		int s = c;
		cout << "hello,world, x :" << x << endl;	
		cout << "a = " << a << endl
			 << "b = " << b << endl
			 << "c = " << c << endl;
	};
	f(10);
}

int main(void)
{
	test0();
	return 0;
}
