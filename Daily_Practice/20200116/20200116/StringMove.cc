#include <string.h>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class String
{
public:
    String()
    {
        cout<<"String()"<<endl;
    }



    String(const char * pstr)
    :_pstr(new char[strlen(pstr)+1]())
    {
        cout<<"String(const char *)"<<endl;
        strcpy(_pstr,pstr);
    }

    String(String &&rhs)
    {
        cout<<"String(String &&)"<<endl;
        _pstr=rhs._pstr;
        rhs._pstr=nullptr;
    }
    
    String & operator=(String &&rhs)
    {
        cout<<"String & operator=(String &&)"<<endl;
        if(this!=&rhs)
        {
           // delete _pstr;
            _pstr=rhs._pstr;
            rhs._pstr=nullptr;
        }
        return *this;
    }

    void print() const
    {
        cout<<_pstr<<endl;
    }

private:
    char * _pstr;
};








int main()
{
    String s1="hello,world";
    s1.print();
    String s2=std::move(s1);
    //std::move(s1);
    s2.print();
    String s3("AMD YES");
    s3.print();
    //String && ref = "hello,world";
    //String s4(String("wuhan"));   
    s3=String("wuhan");
    s3.print();
   // s4.print();
   // String s4=ref;
    /* String s5=ref; */
    
    
        return 0;
}
