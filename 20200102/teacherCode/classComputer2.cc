 ///
 /// @file    Computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-02 17:23:54
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

//代码规范:
//1. 自定义类类型以大写字母开头
//2. 数据成员以下划线开始
//3. 成员函数以小写字母开头，驼峰形式展开
//4. 数据成员统一放到类的底部, 在类的开始位置
//   放置的应该是类提供的功能、接口、服务
//
class Computer
{//类内部
//默认情况下，内部全部是private的
public:
	//成员函数的声明
	void setBrand(const char * brand);
	void setPrice(float price);

	void print();

private:
	char _brand[20];
	float _price;// price_   m_price
};

//在类之外定义成员函数
void Computer::setBrand(const char * brand)
{
	strcpy(_brand, brand);
}

void Computer::setPrice(float price)
{
	_price = price;
}

void Computer::print()
{
	cout << "_brand:" << _brand << endl
		 << "_price:" << _price << endl;
}
 
int main(void)
{
	Computer com;
	com.setBrand("Macbook pro");
	com.setPrice(20000);
	com.print();

	return 0;
}
