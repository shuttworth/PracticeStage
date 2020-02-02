#include <iostream>

using std::cout;
using std::endl;

class Sinleton
{
    private:
       static  Sinleton * _pInstance;
    public:
        static Sinleton * getInstance()
        {
            if(!_pInstance)
            {
                _pInstance=new Sinleton();
                return 0;
            }
            return _pInstance;
        }

        static void destroy()
        {
            if(_pInstance)
            {
                delete _pInstance;
            }
        }

    private:
        Sinleton()
        {
            cout<<"Sinleton()"<<endl;
        }

        ~Sinleton()
        {
            cout<<"~Sinleton()"<<endl;
        }
};

Sinleton * Sinleton::_pInstance=NULL;

int main()
{
    Sinleton * p1=Sinleton::getInstance();
    Sinleton * p2=Sinleton::getInstance();
    Sinleton * p3=Sinleton::getInstance();
    cout<<"p1="<<p1<<endl;
    cout<<"p2="<<p2<<endl;
    cout<<"p3="<<p3<<endl;
    Sinleton::destroy();
    return 0;
}

