 ///
 /// @file    VariadicTemplateParameter.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-20 14:33:08
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <class... Args>
void printParameterSize(Args... args)
{
	cout << "sizeof...(args): " << sizeof...(args) << endl;
	cout << "sizeof...(Args): " << sizeof...(Args) << endl;
}
 
#if 0
template <class... Args>
void print(Args... args)
{
	cout << (args) << endl;
}
#endif

//递归的出口条件
#if 0
void display()
{	cout << endl;	}
#endif

template <class T>
void display(T t)
{
	cout << t << endl;
}


template <class T, class... Args> //声明的时候 Args在...的右边， 称为模板参数包
void display(T t, Args... args) //args在...的右边， 称为函数参数包
{
	cout << t << " ";
	//args...    //使用的时候，args在...的左边， 称为参数包的展开
	display(args...);//递归展开, 必须要有一个出口
}

int main(void)
{
	printParameterSize("hello", 1, 1.1, 'a');
	display("hello", 1, 1.1, 'a');
	// cout << "hello" << " ";
	// display(1, 1.1, 'a');
	//		cout << 1 << " ";
	//		display(1.1, 'a');
	//			cout << 1.1 << " ";
	//			display('a');
	//				cout << 'a' << " ";
	//				display();

 
	return 0;
}
