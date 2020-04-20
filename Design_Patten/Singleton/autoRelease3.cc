#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

using std::cout;
using std::endl;
using std::string;

class Singleton
{
public:
    static Singleton * getInstance()
    {
        pthread_once(&_once,init);
        return _pstr;
    }

    static void init()
    {
        _pstr = new Singleton();
        ::atexit(destroy);
    }

    static void destroy()
    {
        if(_pstr)
        {
            delete _pstr;
        }
    }

private:
    Singleton()
    {
        cout<<"Singleton()"<<endl;
    }

    ~Singleton()
    {
        cout<<"~Singleton()"<<endl;
        if(_pstr){
            _pstr = nullptr;
        }
    }

    static Singleton * _pstr;
    static pthread_once_t _once;
};

Singleton* Singleton:: _pstr = nullptr;
pthread_once_t Singleton:: _once = PTHREAD_ONCE_INIT;


int main()
{
    /* Singleton s; */
    Singleton * s1 = Singleton::getInstance();
    Singleton * s2 = Singleton::getInstance();
    cout<<s1<<endl;
    cout<<s2<<endl;
    /* s1->destroy(); */
    /* s2->destroy(); */

    return 0;
}

