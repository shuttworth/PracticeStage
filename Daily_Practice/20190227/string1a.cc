#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class string{
private:
    char * _pstr;
public:
    string()
        :_pstr(new char[1]())//默认构造不传参
    {
        cout<<"string()"<<endl;
    }

    string(const char * pstr)//传参构造
        :_pstr(new char[strlen(pstr)+1]())
    {
        strcpy(_pstr,pstr);
        cout<<"string(const char * pstr)"<<endl;
    }

    string(const string & rhs)//复制构造函数
        :_pstr(new char[strlen(rhs._pstr)+1]())
    {
        strcpy(_pstr,rhs._pstr);
        cout<<"string(const char * pstr)"<<endl;
    }



    string & operator=(const string & rhs)//赋值运算符函数
    {
        if(&rhs!=this)
        {
            delete [] _pstr;
        _pstr=new char[strlen(rhs._pstr)+1]();
        strcpy(_pstr,rhs._pstr);
        }
        return *this; 
    }

        ~string()
        {
            if(_pstr)
            {
                delete [] _pstr;
                cout<<"~string()"<<endl;
            }
        }




        void print()
        {
            if(_pstr)
            {
                cout<<_pstr<<endl;
            }
        }

};


int   main()
{
    string str1;
    str1.print();//调用最一开始的默认构造部分

    string str2="hello,world";
    string str3("wangdao");//这两种写法都相当于给它传参

    str2.print();
    str3.print();

    string str4=str3;
    str4.print();//复制

    str4=str2;
    str4.print();//赋值运算符

}
