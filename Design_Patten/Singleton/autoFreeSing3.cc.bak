#include <stdlib.h>
#include <pthread.h>
#include <iostream>

using std::cout;
using std::endl;

class Singleton
{
public:
    static Singleton * getInstance()
    {
        pthread_once(&_once,init); //保证init只执行一次
        cout<<"getInstance()"<<endl;
        return _pstr;
    }

    static void init()
    {
        cout<<"init()"<<endl;
        atexit(destroy);
    }

    static void destroy()
    {
        cout<<"destroy()"<<endl;
        delete  _pstr;
    }

    void print()
    {
        cout<<_pstr<<endl;
    }

private:

    Singleton(){cout<<"Singleton()"<<endl;}
    ~Singleton(){
        if(_pstr)
        {
            _pstr=nullptr;
            cout<<"~Singleton()"<<endl;
        }
    }

private:

private:
    static Singleton * _pstr;
    static pthread_once_t _once; //pthread_once_t 是类型
};

Singleton *Singleton::_pstr=nullptr;
/* Singleton::AutoRealease Singleton::_ar; //构造了一个，需要析构它 */
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;//用它来初始化Singleton里的变量


int main()
{
    Singleton*  s1=Singleton::getInstance();
    Singleton*  s2=Singleton::getInstance();
    s1->print();
    s2->print();
    return 0;
}

