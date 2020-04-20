#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class String
{
public:
    String()
        :_pstr(new char[1]())
    {
        cout<<"string()"<<endl;
    }

    String(const char *pstr)
        :_pstr(new char[strlen(pstr)+1]())
    {
        strcpy(_pstr,pstr);
        cout <<"String(const char *pstr)"<<endl;
    }

    String(const String & rhs)
        :_pstr(new char[strlen(rhs._pstr)+1]())
    {
        strcpy(_pstr,rhs._pstr);
        cout <<"String(const string & rhs)"<<endl;
    }

    String & operator=(const String & rhs)
    {
        if(this!=&rhs)
        {
            delete [] _pstr;
            _pstr=new char[strlen(rhs._pstr)+1]();
            cout<<" String & operator=(const String & rhs)"<<endl;
        }
        return *this; 
    }

    ~String()
    {
        delete [] _pstr;
        cout<<"~string()"<<endl;
    }

    void print()
    {
        if(_pstr)
        {
            cout<<_pstr<<endl;
        }
    }

private:
    char * _pstr;
};

int main(void)
{
    String str1;
    str1.print();

    String str2 = "Hello,world";
    String str3("wangdao");

    str2.print();
    str3.print();

    String str4 = str3;
    str4.print();

    str4 = str2;
    str4.print();

    return 0;
}
