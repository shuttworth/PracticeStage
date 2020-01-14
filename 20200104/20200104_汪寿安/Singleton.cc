#include <iostream>
#include <string.h>
using namespace std;

class singleton
{
public:
    static singleton * getInstance()
    {
        if(pstr==nullptr)
        {
            pstr=new singleton(); //new 不仅开辟空间，而且返回指针
            //strcpy(pstr,"Assissan Creed");
            cout<<"static singleton * getInstance()"<<endl;
        }
        return pstr;
    }

    void print()
    {
        cout<<pstr<<endl;
    }

private:
    singleton(){
        cout<<"singleton() "<<endl;
    }

    ~singleton()
    {
        if(pstr)
        {
            cout<<"~singleton()"<<endl;
            delete pstr;
        }
    }

    //static char * pstr; error
    static singleton * pstr;

};

singleton * singleton::pstr=nullptr;

int main()
{
    singleton * s1= singleton::getInstance();
    singleton * s2= singleton::getInstance();
    singleton * s3= singleton::getInstance();
    s1->print();
    s2->print();
    s3->print();
    return 0;
}

