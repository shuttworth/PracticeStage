#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class string{
    public:
        string()// 无参型
            :_pstr(new char[1]())
        {
            cout<<"string()"<<endl;
        }

        string(const char *pstr) //有参型
        :_pstr(new char[strlen(pstr)+1]())//加小括号()的时候会初始化为0,不加小括号内部值不确定
        {
                strcpy(_pstr,pstr);
                cout<<"string(const char *_pstr)"<<endl;
        }

        string(const string & rhs) //传进来的rhs是一个类名
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
                _pstr =new char[strlen(rhs._pstr)+1]();
                strcpy(_pstr,rhs._pstr);
            }
            return *this;
        }

        ~string()
        {
            cout << "~string()" <<endl;
        }

        void print()
        {
            if(_pstr)
            {
            cout << _pstr <<endl;
            }
        }

    private:
        char * _pstr;
};


int main(void)
{
    string str1;
    str1.print();

    string str2 = "hello,world";
    string str3("wangdao");

    str2.print();
    str3.print();

    string str4 =str3;
    str4.print();

    str4=str2;
    str4.print();

    return 0;
}
