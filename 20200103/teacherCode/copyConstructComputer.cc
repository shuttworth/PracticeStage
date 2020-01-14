 ///
 /// @file    Computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-03 10:59:46
 ///
 
#include <string.h>

#include <iostream>
using std::cout;
using std::endl;


class Computer
{
public:
	Computer(const char * brand, float price)
	//: _brand(brand) //浅拷贝
	: _brand(new char[strlen(brand) + 1]())
	, _price(price)
	{
		cout << "Computer(const char *, float)" << endl;
		strcpy(_brand, brand);//深拷贝
	}

#if 0
	//默认的拷贝构造函数不再满足当前的需求
	//必须显式提供
	Computer(const Computer & rhs)
	: _brand(rhs._brand) //浅拷贝
	, _price(rhs._price)
	{
	
	}
#endif

	Computer(const Computer & rhs)
	: _brand(new char[strlen(rhs._brand) + 1]())
	, _price(rhs._price)
	{
		cout << "Computer(const Computer &)" << endl;
		strcpy(_brand, rhs._brand);
	}

	void print()
	{
		printf("&_brand: %p\n", _brand);
		cout << "brand:" << _brand << endl
			 << "price:" << _price << endl;
	}

	//由于数据成员_brand指向了堆空间的区域，
	//所以必须要显式提供一个析构函数进行回收
	//
	//析构函数要清理的是对象的数据成员申请的资源
	//而对象本身所占据的空间，不是由析构函数来回收的
	//
	//只要对象被销毁，就会自动调用析构函数
	//
	~Computer()
	{
		delete [] _brand;
		cout << "~Computer()" << endl;
	}

private:
	char * _brand;// 8    字节对齐
	float _price;//  4
};

//main函数退出之后，全局对象会自动被销毁
//Computer pc3("Thinkpad", 8888);
 
int test0(void)
{
	//sizeof发生时机是编译时
	cout << "sizeof(Computer): " << sizeof(Computer) << endl;
	Computer pc1("Macbook pro", 20000);// 栈对象
	pc1.print();

	//堆对象
	Computer * pc2 = new Computer("Alien", 20000);
	pc2->print();

	//显式调用析构函数, 并不建议显式调用
	//pc2->~Computer();//对象本身没有被回收的
	delete pc2;//只有delete表达式才能回收对象占据的空间

	cout << endl;
	//pc3.print();

	static Computer pc4("Xiaomi", 7777);
	pc4.print();
 
	return 0;
}

void test1()
{
	cout << "sizeof(Computer): " << sizeof(Computer) << endl;
	Computer pc1("Macbook pro", 20000);
	cout << "pc1:";
	pc1.print();

	int x = 1;
	int y = x;

	Computer pc2 = pc1;//调用拷贝构造函数
	cout << "pc2:";
	pc2.print();

	Computer pc3(pc1);
}

int main()
{
	//test();
	test1();
	cout << "exit main..." << endl;
	return 0;
}
