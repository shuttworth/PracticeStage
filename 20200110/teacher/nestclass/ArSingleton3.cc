 ///
 /// @file    Singleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-10 16:44:56
 ///

#include <stdlib.h>
#include <pthread.h>  //POSIX标准的线程库

#include <iostream>
using std::cout;
using std::endl;


//平台相关性用法
//单例对象自动释放的实现方式之三:
//	pthread_once + atexit 

class Singleton
{
public:
	static Singleton * getInstance()
	{
		pthread_once(&_once, init);
		return _pInstance;
	}

	static void init()
	{
		_pInstance = new Singleton();
		atexit(destroy);
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
	static pthread_once_t _once;
};


Singleton * Singleton::_pInstance = nullptr;
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;
 
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
