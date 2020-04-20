#include <iostream>
using std::cout;
using std::endl;

//  ... 代表任意类型的参数
template <typename... Args>  //模板参数包
void display(Args... args)  //函数参数包
{
	//sizeof...  求取可变模板参数的个数
	cout << sizeof...(Args) << endl;//sizeof在编译期就已经确定
	cout << sizeof...(args) << endl;
}

#if 0  //没有参数的时候，当做出口出来
void print()
{
	cout << endl;
}
#endif

template <typename T>
void print(T t)  //当这个print方法只有一个参数的时候，当做出口出来
{
	cout << t << endl;
}

template <typename T, typename... Args>
void print(T t, Args... args) 
{
	cout << t << endl;
	print(args...);//对print的递归调用
}

template <typename T>
T sum(T t)
{
	return t;
}

template <typename T, typename ...Args>
T sum(T t, Args... args)
{
	return t + sum(args...);
}

 
int main(void)
{
	display(1, 1.1, 'A', "hello,world");
	print(1, 1.1, 'A', "hello,world");//下面展示递归的过程
	//cout << 1 << endl;
	//print(1.1, 'A', "hello,world");
	//	cout << 1.1 << endl;
	//	print('A', "hello,world");
	//		cout << 'A' << endl;
	//		print("hello,world");
	//			cout << "hello,world" << endl;

	cout << sum(1, 2, 3, 4, 5) << endl;
	// return 1 + sum(2, 3, 4, 5);
	// return 1 + 2 + sum(3, 4, 5);
	// return 1 + 2 + 3 + sum(4, 5);
	// return 1 + 2 + 3 + 4 + sum(5);
	// return 1 + 2 + 3 + 4 + 5;
	//
	return 0;
}
