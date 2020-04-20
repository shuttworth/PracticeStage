 ///
 /// @file    Singleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-10 16:44:56
 ///

#include <stdlib.h>

#include <iostream>
using std::cout;
using std::endl;


//单例对象自动释放的实现方式之一: atexit + destroy

class Singleton
{
public:
	static Singleton * getInstance()
	{
		//在多线程环境下是非线程安全的
		//加锁
		if(nullptr == _pInstance) {
			::atexit(destroy);
			_pInstance = new Singleton();
		}
		return _pInstance;
	}

	static void destroy()
	{
		if(_pInstance)
			delete _pInstance;
	}

private:
	Singleton() {	cout << "Singleton()" << endl;	}
	~Singleton() {	cout << "~Singleton()" << endl;	}

private:
	static Singleton * _pInstance;
};

//饱(懒)汉模式  --> 懒加载(lazy )
//Singleton * Singleton::_pInstance = nullptr;

//饿汉模式 可以解决线程安全的问题
Singleton * Singleton::_pInstance = getInstance();
 
int main(void)
{
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();
	cout << "p1 = " << p1 << endl
		 << "p2 = " << p2 << endl;


	//AutoRelease ar;//error

	//Singleton::destroy();
	return 0;
}
