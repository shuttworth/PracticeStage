#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class CharArray
{
private:
    int _size;
    char * _pdata;

public:
    CharArray(int size)
        :_size(size)
         ,_pdata(new char[_size]())
    {
        cout<<"CharArray(int size)"<<endl;
    }

    char & operator[](int idx)
    {
        cout<<"  char & operator[](int idx)"<<endl;
        static char nullchar='\0';
        if(idx<0||idx>=_size)
        {
            cout<<"数组越界"<<endl;
            return nullchar;
        }
        else {
            return _pdata[idx];
        }
    }
};




int main()
{
    const char * pstr="hello,world";
    int len=strlen(pstr)+1;
    CharArray ca(len);

    for(int idx=0;idx!=len;++idx)
    {
       ca[idx]=pstr[idx];  //ca  是 CharArray 类型的，所以会调用 public 里的数组下标重载

    }

    for(int idx=0;idx!=len;++idx)
    {
        cout<<ca[idx];
    }
    cout<<endl;
    return 0;
}

