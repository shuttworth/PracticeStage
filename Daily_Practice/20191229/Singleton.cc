#include <iostream>
using std::cout;
using std::endl;

class Singleton{

private:
    static Singleton * _pInstance;
public:
    static Singleton * getInstance(){
        if(!_pInstance)
        {
            _pInstance =new Singleton();
            return 0;
        }
        else return _pInstance;
    }

    static void destroy(){
        if(_pInstance)
        {
            delete _pInstance;
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
    }

};

Singleton * Singleton::_pInstance=NULL;


int main()
{
    Singleton* p1=Singleton::getInstance();
    Singleton* p2=Singleton::getInstance();
    Singleton* p3=Singleton::getInstance();
    cout<<"p1="<<p1<<endl;
    cout<<"p2="<<p2<<endl;
    cout<<"p3="<<p3<<endl;
    return 0;
}

