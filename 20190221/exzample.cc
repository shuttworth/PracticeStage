 ///
 /// @file    Computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-10-26 17:27:11
 ///

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{// 大括号范围称为类内部
// Computer的默认访问权限是private
public:
	void setBrand(const char * brand)
	{
		strcpy(_brand, brand);
	}

void setPrice(float price)
{
	_price = price;//类成员的前面统一加下划线，作为代码的风格
}

void print()
{
	cout << "品牌:" << _brand << endl
		 << "价格:" << _price << endl;
}


protected:
	float _price;//m_price/price_/c_price

private:// 表达封装特性, 在类之外不能直接进行访问
	char _brand[20];
};

int main(void)
{
//	int a;//内置类型


Computer pc1;//自定义类类型
pc1.setBrand("acer");
pc1.setPrice(7000);
pc1.print();

//pc1._brand = 0x100;//error
//pc1._price = 100;//error

pc1.print();

return 0;

}
