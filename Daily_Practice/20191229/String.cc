#include <iostream>
#include <string.h>
#include <stdlib.h>

using std::cout;
using std::endl;

class String
{
private:
    char* _pstr;
public:
    String()
    :_pstr(new char[1]())
    {
        cout<<"String()"<<endl;
    }

    String(const char * pstr)
        :_pstr(new char[strlen(pstr)+1]())
    {
        strcpy(_pstr,pstr);
        cout<<"String(const char * pstr)"<<endl;
    }

    String(const String & rhs)
        :_pstr(new char[strlen(rhs._pstr)+1]())
    {
        strcpy(_pstr,rhs._pstr);
        cout<<"String(const String & rhs)"<<endl;
    }


};


int main()
{
    return 0;
}

