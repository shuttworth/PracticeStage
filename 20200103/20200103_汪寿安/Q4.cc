#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
using std::string;


//实现一个自定义的String类，保证main函数对正确执行
class String
{
public:
	String()
    :_pstr(new char[strlen("Assassin Creed")])
    {

        strcpy(_pstr,"Assassin Creed");
       // _pstr="Assassin Creed";
        cout<<"String()"<<endl;
    }
	
    String(const char *pstr)
    :_pstr(new char[strlen(pstr)+1]())
    {
        strcpy(_pstr,pstr);
        cout<<"String(const char *pstr)"<<endl;
    }
	
    String(const String & rhs)
    :_pstr(new char[strlen(rhs._pstr)+1]())
    {
        strcpy(_pstr,rhs._pstr);
        cout<<"String(const String & rhs)"<<endl;
    }
	
    
    String & operator=(const String & rhs)
   // :_pstr(new char[strlen(rhs._pstr)+1]())
    {
        if(rhs._pstr!=this->_pstr) //这里不严谨，应该用老师的写法
        {
            delete [] _pstr;
            _pstr=new char[strlen(rhs._pstr)+1]();
            strcpy(_pstr,rhs._pstr);
            cout<<"String & operator=(const String & rhs)"<<endl;
        }
            return *this; //这一步是精髓，卡到我了，一开始,想想不难理解，自己赋值自己，那就返回自己
    }
	
    
    ~String()
    {
        if(_pstr)
        {
            delete [] _pstr;
            cout<<"~String()"<<endl;
        }
    }

	void print()
    {
        cout<<_pstr<<endl;
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


