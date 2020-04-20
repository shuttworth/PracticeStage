#include <iostream>
using std::cout;
using std::endl;

class Sinleton
{
public:
    static Sinleton * getinstance()
    {
        if(_pInstance==NULL)
        {
            _pInstance=new Sinleton();
            return 0;
        }
        else return _pInstance;//指针指向创立的Sinleton地址
    }

    static void destroy()
    {
        if(_pInstance!=NULL)
        {
            delete _pInstance;
        }
    }
private:
    Sinleton()
    {
        cout << "Sinleton" << endl;
    }
    ~Sinleton()
    {
        cout << "~Sinleton"<< endl;
    }
private:
    static Sinleton*_pInstance;
};

Sinleton* Sinleton::_pInstance=NULL;


int main()
{
    Sinleton* p1=Sinleton::getinstance();
    Sinleton* p2=Sinleton::getinstance();
    Sinleton* p3=Sinleton::getinstance();
    cout << "p1==" <<p1 <<endl;
    cout << "p2==" <<p2 <<endl;
    cout << "p3==" <<p3 <<endl;
    Sinleton::destroy();
    return 0;
}

