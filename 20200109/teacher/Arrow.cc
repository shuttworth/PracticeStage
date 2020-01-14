 ///
 /// @file    Arrow.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-09 16:03:28
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Data
{
public:
	Data() {	cout << "Data()" << endl;	}

	int getData() const {	return _data;	}

	~Data() {	cout << "~Data()" << endl;	}

private:
	int _data = 10;
};

class MiddleLayer
{
public:
	MiddleLayer(Data * pdata)
	: _pdata(pdata)
	{
		cout << "MiddleLayer()" << endl;
	}

	//指针访问运算符
	//	 返回的是一个指针
	Data * operator->()
	{
		return _pdata;
	}

	Data & operator*()
	{	return *_pdata;	}

	~MiddleLayer()
	{
		cout << "~MiddleLayer()" << endl;
		delete _pdata;
		_pdata = nullptr;
	}

private:
	Data * _pdata;
};

class ThirdLayer
{
public:
	ThirdLayer(MiddleLayer * pml)
	: _pml(pml)
	{
		cout << "ThirdLayer()" << endl;
	}

	//返回的是一个重载了指针访问运算符的对象
	MiddleLayer & operator->()
	{
		return *_pml;
	}

	~ThirdLayer()
	{	
		cout << "~ThirdLayer()" << endl;
		delete _pml;
		_pml = nullptr;
	}

private:
	MiddleLayer * _pml;
};
 
int main(void)
{
	/* Data * p; */
	/* p->getData(); */
	/* (*p).getData(); */

	//用一个对象来管理堆空间的资源
	//
	//智能指针的雏形
	MiddleLayer ml(new Data());
	cout << ml->getData() << endl;
	cout << (*ml).getData() << endl;
	
	//cout << ml.operator->()->getData() << endl << endl;

	/* ThirdLayer tl(new MiddleLayer(new Data())); */
	/* cout << tl->getData() << endl; */
	/* cout << (tl.operator->()).operator->()->getData() << endl; */
	

	return 0;
}
