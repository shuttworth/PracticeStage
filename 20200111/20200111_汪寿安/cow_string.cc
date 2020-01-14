#include <string.h>
#include <iostream>

using std::cout;
using std::endl;
using std::ostream;


class String
{
public:
    class charPorxy;
    String()
        :_pstr(new char[5]()+4)
    {
        cout<<"String()"<<endl;
        initCount();
    }


    String(const char * pstr)
        :_pstr(new char[strlen(pstr)+5]()+4)
    {
        strcpy(_pstr,pstr);
        cout<<"String(const char *)"<<endl;
        initCount();
    }


    String(const String & rhs)
        :_pstr(rhs._pstr) //先不要深拷贝
    {
        cout<<"String(const String & )"<<endl;
        increaseCount();
    }

    String & operator =(const String & rhs)
    {
        cout<<"String & operator =(const String &)"<<endl;
        if(&rhs!=this)
        {
            void release();
                            //_pstr = new char[strlen(rhs._pstr)+5]()+4;此时还不是深拷贝
            _pstr=rhs._pstr;
            increaseCount();
        }
        return *this;
    }


    charPorxy  operator [](size_t index)
    {
        cout<<"charPorxy & operator [](size_t )"<<endl;
        return charPorxy(*this,index); //返回临时嵌套类对象，&去掉是因为嵌套类对象都是临时的
    }    



    ~String()
    {
        cout<<"~String()"<<endl;
        release();
    }

    const char *c_str() const
    {
        return _pstr;
    }

    size_t size() const
    {
        return strlen(_pstr);
    }

    int getCount() const
    {
        return *(int*)(_pstr-4);
    }

    class charPorxy
    {
    public:
        charPorxy(String & str,int idx)
            :_str(str)
             ,_idx(idx)
        {
            cout<<"charPorxy(String &,int)"<<endl;
        }

        //下面这两个函数还可以这么写？？
        char operator =(char ch); //类外写实现,实现写操作

        operator char() //只是读
        {
            cout<<"operator char()"<<endl;
            return _str._pstr[_idx];
        }


    private:
        String & _str; //初始化列表里的初始化顺序受到private里定义的影响
        size_t _idx;
    };

private:
    void initCount()
    {
        *(int*)(_pstr-4)=1;//char * 只访问一个，int *可访问四个
    }

    void increaseCount()
    {
        ++*(int*)(_pstr-4);
    }

    void decreaseCount()
    {
        --*(int*)(_pstr-4);
    }


    void release()
    {
        decreaseCount();
        if(getCount()==0)
        {
            delete [] (_pstr-4);
            cout<<"release()"<<endl;
        }
    }

    size_t size()
    {
        return strlen(_pstr);
    }

    friend ostream & operator << (ostream &os,const String & rhs);

private:
    char * _pstr;

};

char String::charPorxy::operator=(char ch)
{
    size_t sz=_str.size();
    if(_idx>=0&&_idx<sz)
    {
        if(_str.getCount()==1)
        {
            _str[_idx]=ch;
            return _str._pstr[_idx];
        }
        if(_str.getCount()>1)
        {
            char *tmp = new char[strlen(_str._pstr)+5]()+4;
            strcpy(tmp,_str._pstr);
            _str.decreaseCount();
            _str._pstr=tmp;
            _str._pstr[_idx]=ch;
            _str.initCount();
        }
            return _str._pstr[_idx];
    }
    else {
        static char nullchar='\0';
        return nullchar;
    }
}




ostream & operator << (ostream &os,const String & rhs)
{
    os << rhs._pstr;
    return os;
}



void test0()
{

    String s1("hello");
    String s2 = s1;

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;

    cout << "s1's refcount = " << s1.getCount() << endl;
    cout << "s2's refcount = " << s2.getCount() << endl;

    printf("s1's address: %p\n", s1.c_str());
    printf("s2's address: %p\n", s2.c_str());
    cout << endl;
    
    String s3 = "world";
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;

    cout << "s1's refcount = " << s1.getCount() << endl;
    cout << "s2's refcount = " << s2.getCount() << endl;
    cout << "s3's refcount = " << s3.getCount() << endl;

    printf("s1's address: %p\n", s1.c_str());
    printf("s2's address: %p\n", s2.c_str());
    printf("s3's address: %p\n", s3.c_str());

    cout << endl;
    s3 = s1;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;

    cout << "s1's refcount = " << s1.getCount() << endl;
    cout << "s2's refcount = " << s2.getCount() << endl;
    cout << "s3's refcount = " << s3.getCount() << endl;

    printf("s1's address: %p\n", s1.c_str());
    printf("s2's address: %p\n", s2.c_str());
    printf("s3's address: %p\n", s3.c_str());

    cout << endl;
    cout << "修改s3[0] = 'H'之后 :" << endl;
    s3[0] = 'H';
    cout << "s3[0] = " << s3[0] << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;

    cout << "s1's refcount = " << s1.getCount() << endl;
    cout << "s2's refcount = " << s2.getCount() << endl;
    cout << "s3's refcount = " << s3.getCount() << endl;

    printf("s1's address: %p\n", s1.c_str());
    printf("s2's address: %p\n", s2.c_str());
    printf("s3's address: %p\n", s3.c_str());

    cout << endl;
    cout << "对s1[0] 执行读操作之后 :" << endl;
    std::cerr << "s1[0] = "<<s1[0] << endl; //"s1[0] = " 无法输出出来
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;


    cout << "s1's refcount = " << s1.getCount() << endl;
    cout << "s2's refcount = " << s2.getCount() << endl;
    cout << "s3's refcount = " << s3.getCount() << endl;

    printf("s1's address: %p\n", s1.c_str());
    printf("s2's address: %p\n", s2.c_str());
    printf("s3's address: %p\n", s3.c_str());
//#endif
}

int main()
{
    test0();
    return 0;
}

