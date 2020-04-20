#include <iostream>
using std::cout;
using std::endl;

//单例对象的自动释放
//方法一: 嵌套类 + 静态对象  ---- 跨平台


class Singleton 
{
	class AutoRelease
	{
	public:
		AutoRelease(){	cout << "AutoRelease()" << endl;}

		~AutoRelease() {
			cout << "~AutoRelease()" << endl;
			if(_pInstance)
				delete _pInstance;
		}
	};
public:
	static Singleton * getInstance()
	{
		//在多线程环境下是非线程安全的
		//加锁
		if(_pInstance == NULL)
			_pInstance = new Singleton;
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
	static AutoRelease _ar;
	static Singleton * _pInstance;
};

//全局变量是会自动初始化的，即时没有给他一个初值
int a;
int *p;


Singleton::AutoRelease Singleton::_ar;
//Singleton * Singleton::_pInstance = NULL;//懒(饿)汉模式, 进行加锁可以保证线程安全
Singleton * Singleton::_pInstance = getInstance();//线程安全, 饱汉模式

 
int main(void)
{
    cout<<"a="<<a<<endl;
    cout<<"p="<<p<<endl;
   // cout<<"*p="<<*p<<endl;  error

	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();
	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;

	return 0;
}
