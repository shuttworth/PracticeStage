#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class string
{
private:
    char * _pstr;
public:
    string()
        :_pstr(new char[1]())
    {
        cout <<"string()" << endl;  
    }

    string(const char * pstr)
        :_pstr(new char[strlen(pstr)+1]())
    {
        strcpy(_pstr,pstr);
        cout << "string(const char * pstr)" <<endl;
    }

    string(const string & rhs)
        :_pstr(new char[strlen(rhs._pstr)+1]())
    {
        strcpy(_pstr,rhs._pstr);
        cout << "string(const string & rhs)" <<endl;
    }

    string & operator =(const string & rhs)
    {
        if(this!=&rhs)
        { 
            delete [] _pstr;
            _pstr=new char[strlen(rhs._pstr)+1]();
            strcpy(_pstr,rhs._pstr);
            cout << "string & operator =(const string & rhs)" <<endl;
        }
        return * this;
    }

    ~string()
    {
        cout << "~string()" <<endl;
    }

    void print()
    {
        if(_pstr)
        {
            cout << _pstr << endl;
        }
    }
};


int main(void)
{
    string str1;
    str1.print();

    string str2 = "Hello,world";
    string str3("wangdao");

    str2.print();
    str3.print();

    string str4 = str3;
    str4.print();

    str4 = str2;
    str4.print();

    return 0;
}
