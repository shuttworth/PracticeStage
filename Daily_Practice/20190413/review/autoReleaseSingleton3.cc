#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

//单例对象的自动释放
//方法三: atexit + pthread_once(POSIX) ---- 平台相关性

//pthread_once方法能够注册init_routine函数，它能够保证init_routine函数
//在多线程环境之下，只会被调用一次

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
		atexit(destroy);
		_pInstance = new Singleton;
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
	static pthread_once_t _once;
	static Singleton * _pInstance;
};

pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

Singleton * Singleton::_pInstance = NULL;//懒(饿)汉模式
//Singleton * Singleton::_pInstance = getInstance();//饱汉模式

 
int main(void)
{
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();
	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;

	return 0;
}
