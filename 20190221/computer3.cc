
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class Computer
{
public:
	Computer(const char * brand, float price)
	: _brand(new char[strlen(brand) + 1]())
	, _price(price)
	{
		strcpy(_brand, brand);
		cout << "Computer(const char*, float)" << endl;
	}

//析构函数可以显式调用，但调用析构函数并不代表对象被销毁了；
//如果对象被销毁，一定会调用析构函数
~Computer()
{
	delete [] _brand;
	cout << "~Computer()" << endl;
}

void print() 
{
	cout << "品牌:" << _brand << endl
		 << "价格:" << _price << endl;
}

private:
	char * _brand;
	float _price;
};

Computer gCom("Mac", 9999);

int test0(void)
{
	cout << "enter main() " << endl;
	Computer c1("xiaomi", 7777);//栈上
	c1.print();

{
	Computer c2("ACER", 6666);
	c2.print();
}
cout << "exit main()" << endl;
return 0;

}

int main(void)
{
	Computer * p1 = new Computer("zhanshen", 9999);//堆对象
	p1->print();
//	p1->~Computer();//显式调用析构函数

delete p1;
test0();
return 0;

}
