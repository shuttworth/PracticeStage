 ///
 /// @file    Singleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-04 11:30:15
 ///
 
#include <iostream>
using std::cout;
using std::endl;


//单例模式
//要求: 通过一个类只能生成一个对象
//
//
//应用场景:
//1. 全局对象的地方，都可以考虑使用单例模式
//2. 读取配置文件, 配置文件的内容就可以使用单例对象存放
//3. 词典库、网页库

class Singleton
{
public:
	static Singleton * getInstance()
	{
		if(_pInstance == nullptr) {
			_pInstance = new Singleton();
		}
		return _pInstance;
	}

	static void destroy() //汪寿安问：这个static 是否需要？因为对象已经创建，不需要类名访问
	{
		if(_pInstance)
			delete _pInstance;
	}

	void print() const
	{	cout << "Singleton::print()" << endl;	}

private:
	Singleton() {cout << "Singleton()" << endl;	}
	~Singleton() {	
		cout << "~Singleton()" << endl;
		if(_pInstance)
			_pInstance = nullptr; //防止野指针，重要
	}

	static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance = nullptr;

//Singleton s3;//error
 
int main(void)
{
	//Singleton s1;//error 该语句不能让它编译通过
	//Singleton s2;
	//...
	
	//Singleton * ps1 = new Singleton();//error
	//Singleton * ps2 = new Singleton();//
	Singleton * ps1 = Singleton::getInstance();
	Singleton * ps2 = Singleton::getInstance();
	cout << "ps1 = " << ps1 << endl
		 << "ps2 = " << ps2 << endl;

	//delete ps1;//error
	Singleton::getInstance()->print();
	
	Singleton::destroy();

	return 0;
}
