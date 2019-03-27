#include <iostream>
using std::cout;
using std::endl;


class Data
{
public:
	Data(int data = 0)
	: _data(data)
	{	cout << "Data()" << endl;	}

	int getData() const
	{	return _data;	}

	~Data() {	cout << "~Data()" << endl;	}
private:
	int _data;
};

class MiddleLayer
{
public:
	MiddleLayer(Data * pdata)
	: _pdata(pdata)
	{	cout << "MiddleLayer()" << endl;}

	//在后面的智能指针中会用到
	//重载指针运算符
	Data * operator->()
	{	return _pdata;	}

	//解引用运算符
	Data & operator*()
	{	return *_pdata;	}


	~MiddleLayer()
	{
		cout << "~MiddleLayer()" << endl;
		if(_pdata)
			delete _pdata;
	}

private:
	Data * _pdata;
};

class ThirdLayer
{
public:
	ThirdLayer(MiddleLayer * pml)
	: _pml(pml)
	{	cout << "ThirdLayer()" << endl;	}

	MiddleLayer & operator->()
	{
		return *_pml;
	}

	~ThirdLayer() {
		cout << "~ThirdLayer()" << endl;
		if(_pml) 
			delete _pml;
	}

private:
	MiddleLayer * _pml;
};

int main(void)
{
	{
	MiddleLayer ml(new Data(10));
	cout << ml->getData() << endl;//简写过程
	cout << (ml.operator->())->getData() << endl;

	cout << (*ml).getData() << endl;
	}
	cout << endl;

	ThirdLayer tl(new MiddleLayer(new Data(20)));
	cout << tl->getData() << endl;
	cout << ((tl.operator->()).operator->())->getData() << endl;

	return 0;
}
