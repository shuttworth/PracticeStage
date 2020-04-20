#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

//单例对象的自动释放
//方法二: atexit + destroy


class Singleton 
{
public:
	static Singleton * getInstance()
	{
		//在多线程环境下是非线程安全的
		//加锁
		if(_pInstance == NULL) {
			_pInstance = new Singleton;
			atexit(destroy);
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
int a;
int *p;
//Singleton * Singleton::_pInstance;//懒(饿)汉模式, 进行加锁可以保证线程安全
Singleton * Singleton::_pInstance = getInstance();//线程安全, 饱汉模式

 
int main(void)
{
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();
	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;

	return 0;
}
