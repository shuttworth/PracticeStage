#include <string.h>
#include <iostream>

using std::cout;
using std::endl;


class String
{
private:
    char *_pstr;
public:
    String()
        :_pstr(new char[1]())
    {
        cout<<"String()"<<endl;
    }

    String(const char *pstr)
        :_pstr(new char[strlen(pstr)]())
    {
        strcpy(_pstr,pstr);
        cout<<"String(const char *pstr)"<<endl;
    }

    ~String()
    {
        cout<<"~String()"<<endl;
    }

    String(const String & rhs)
        :_pstr(new char[strlen(rhs._pstr)]())
    {
        strcpy(_pstr,rhs._pstr);
        cout<<"String(const String & rhs)"<<endl;
    }

    String & operator =(const String & rhs)
    {
        if(&rhs!=this)
        {
            delete [] this->_pstr;
            _pstr=new char[strlen(rhs._pstr)+1]();
            strcpy(_pstr,rhs._pstr);
            cout<<"String & operator =(const String & rhs)"<<endl;
        }
        return * this; //方便连续赋值
    }

    void print()
    {
        if(_pstr)
        {
            cout<<_pstr<<endl;
        }
    }
};

int main()
{
    
    String str1;
    str1.print();

    String str2 = "hello,world";
    String str3("wangdao");

    str2.print();
    str3.print();

    String str4 =str3;
    str4.print();

    str4=str2;
    str4.print();


    return 0;
}

