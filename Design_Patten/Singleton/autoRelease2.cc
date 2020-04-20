#include <iostream>
#include <string.h>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::string;

class Singleton
{
public:
    static Singleton * getInstance()
    {
        if(_pstr==nullptr)
        {
            _pstr = new Singleton();
            ::atexit(destroy);
        }
        return _pstr;
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

};

 Singleton* Singleton:: _pstr = nullptr;



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

