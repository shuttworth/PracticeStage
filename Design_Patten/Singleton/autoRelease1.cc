#include <iostream>
#include <string.h>

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

private:
    class autoRelease
    {
    public:
        ~autoRelease()
        {
            if(_pstr)
            {
                delete _pstr;
            }
        }

    };

private:
    static autoRelease  _ar;
    static Singleton * _pstr;


};

Singleton* Singleton:: _pstr = nullptr;
Singleton::autoRelease Singleton::_ar; //静态成员变量需要在类外初始化,即使不赋值也要写出来

//类中类，自动释放

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

