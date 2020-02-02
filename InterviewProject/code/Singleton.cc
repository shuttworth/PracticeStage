#include<iostream>

using std::cout;
using std::endl;

class Sinleton
{
    private:
        static Sinleton * _pInstance;
    public:
        static Sinleton * getInstance()
        {
            if(!_pInstance)
            {
                _pInstance=new Sinleton();
                return 0;
            }
            else return _pInstance;
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

Sinleton * Sinleton::_pInstance=NULL;//通过静态访问,在外面赋值

int main(void)
{
    Sinleton* p1=Sinleton::getInstance();
    Sinleton* p2=Sinleton::getInstance();
    Sinleton* p3=Sinleton::getInstance();
    cout<<"p1=="<<p1<<endl;
    cout<<"p1=="<<p2<<endl;
    cout<<"p1=="<<p3<<endl;
    Sinleton::destroy();
}
