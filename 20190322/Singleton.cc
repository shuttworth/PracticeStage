#include <iostream>
using std::cout;
using std::endl;

//单例对象的自动释放
//方法一: 嵌套类 + 静态对象 


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
	static AutoRelease _ar;    //如果_ar不是静态的，一举一动和Singleton类想一致,但是如果放在静态区，当主函数退出就会自动释放
	static Singleton * _pInstance;
};

Singleton::AutoRelease Singleton::_ar;
Singleton * Singleton::_pInstance = NULL;

 
int main(void)
{
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();
	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;

	return 0;
}
