#include <iostream>
using std::cout;
using std::endl;


class singleton
{
    public:
        static singleton * getInstance()
        {
            if(_pstr==nullptr)
            {
                _pstr = new singleton();
                //_pstr = "Assissan's Creed"; error
                cout<<"static singleton * getInstance()"<<endl;
            }
            return _pstr;
        }

        static void destroy() //老师加上了static
        {
            if(_pstr)
            {
                delete _pstr;
                //~singleton(); error
                cout<<"static singleton * destroy()"<<endl;
            }
        }



        void print()
        {
            cout<<_pstr<<endl;
        }

    private:
        singleton()
        {
            cout<<"singleton()"<<endl;
        }
        ~singleton(){
            if(_pstr!=nullptr)
            {
                _pstr=nullptr;
            }
            cout<<"~singleton()"<<endl;
        }
        static singleton * _pstr;
};

singleton* singleton::_pstr = nullptr;




int main()
{
    singleton * s1 = singleton::getInstance();
    singleton * s2 = singleton::getInstance();
    singleton * s3 = singleton::getInstance();
    
    s1->print();
    s2->print();
    s3->print();
    
    s1->destroy();
    s2->destroy();
    s3->destroy();
    
    
    return 0;
}

