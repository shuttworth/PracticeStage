#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

class Singleton
{
public:
    static Singleton * getInstance()
    {
        if(!_pstr)
        {
            ::atexit(destroy);//注册终止函数(即main执行结束后调用的函数,不加（）)
            _pstr=new Singleton();
            cout<<"getInstance()"<<endl;
        }
        return _pstr;
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
    /* class AutoRealease */
    /* { */
    /* public: */
    /*     AutoRealease() */
    /*     { */
    /*         cout<<"AutoRealease()"<<endl; */
    /*     } */

    /*     /1* AutoRealease & operator =(const AutoRealease & rhs) *1/ */
    /*     /1* { *1/ */
    /*     /1*     _ar= *1/ */
    /*     /1* } *1/ */

    /*     ~AutoRealease() */
    /*     { */
    /*         if(_pstr) */
    /*         { */
    /*             delete  _pstr; //直接把pstr删掉，就是一个指针 */
    /*             cout<<"~AutoRealease()"<<endl; */
    /*         } */
    /*     } */
    /* }; */

private:
    static Singleton * _pstr;
    /* static AutoRealease _ar; */

};

Singleton *Singleton::_pstr=nullptr;
/* Singleton::AutoRealease Singleton::_ar; //构造了一个，需要析构它 */

int main()
{
    Singleton*  s1=Singleton::getInstance();
    Singleton*  s2=Singleton::getInstance();
    s1->print();
    s2->print();
    return 0;
}

