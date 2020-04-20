#include <stdio.h>
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class String
{
private:
    char * _pstr;
public:
    String()
        :_pstr(new char[5]()+4)
    {
        initRefcount();
    }

    String(const char * pstr)
        : _pstr(new char[strlen(pstr)+5]()+4)
    {
        strcpy(_pstr,pstr);
        initRefcount();
    }

    String(const String & rhs)
        :_pstr(rhs._pstr)
    {
        strcpy(_pstr,rhs._pstr);
    }

    ~String()
    {
        release();
    }

    void release()
    {
        decreaseRefcount();
        if(refcount()==0)
        {
            delete [] (_pstr-4);
            cout<<">>> delete data"<<endl;
        }
    }

    String & operator = (const String & rhs)
    {
        cout<<"String & operator = (const String & rhs)"<<endl;
        if(this!=&rhs) //this 是个指针，即地址，需要取rhs的地址
        {
            release();
            _pstr=rhs._pstr;
            increaseRefcount();
        }
        return *this;
    }

    friend std::ostream & operator << (std::ostream & os,const String & rhs);

    const char * c_str() const
    {
        return _pstr;
    }

    int refcount() const 
    {
        return *reinterpret_cast<int*>(_pstr-4);
    }

    int size() const
    {
        return strlen(_pstr);
    }
    //对[]下标运算符重载
    char & operator[](int idx)
    {
        static char nullchar = '\0';
        if(idx <0 ||idx>=size())
        {
            cout<<"数组越界"<<endl;
            return nullchar;
        }else 
        {
            if(refcount()>1)
            {
                decreaseRefcount();
                char * ptmp=new char [size()+5]()+4;
                strcpy(ptmp,_pstr);
                _pstr=ptmp;
                initRefcount();
            }
            return _pstr[idx];
        }
    }



private:
    void initRefcount()
    {//reinterpret_cast强制类型转换
        *reinterpret_cast<int *>(_pstr-4)=1;
    }

    void increaseRefcount()
    {
        ++*reinterpret_cast<int *>(_pstr-4);
    }

    void decreaseRefcount()
    {
        --*reinterpret_cast<int *>(_pstr-4);
    }

};

//对ostream类型的<<进行重载
std::ostream & operator << (std::ostream & os,const String & rhs)
{
    os<<rhs._pstr;
    return os;
}





int main(void)
{
    String s1="hello,wolrd";
    String s2;
    cout<<"s1 ="<<s1<<endl;
    cout<<"s2 ="<<s2<<endl;
    printf("s1's address :%p\n",s1.c_str());
    printf("s2's address :%p\n",s2.c_str());
    cout<<"s1' refcount ="<<s1.refcount()<<endl;
    cout<<"s2' refcount ="<<s2.refcount()<<endl<<endl;

    String s3="wangdao";
    String s4(s3); //传rhs ,复制操作
    cout<<"s3="<<s3<<endl;
    cout<<"s4="<<s4<<endl;
    s2=s3;
    cout<<"执行赋值操作"<<endl;
    cout<<"s2 ="<<s2<<endl;
    printf("s2's address : %p\n",s2.c_str());
    printf("s3's address : %p\n",s3.c_str());
    printf("s4's address : %p\n",s4.c_str());

    cout<<"s2's refcount ="<<s2.refcount()<<endl;
    cout<<"s3's refcount ="<<s3.refcount()<<endl;
    cout<<"s4's refcount ="<<s4.refcount()<<endl;


    s3[0]='X';
    cout<<"对下标执行写操作:"<<endl;

    cout<<"s2 ="<<s2<<endl;
    cout<<"s3 ="<<s3<<endl;
    cout<<"s4 ="<<s4<<endl;
    

    printf("s3's address: %p\n", s3.c_str());
    printf("s2's address: %p\n", s2.c_str());
    printf("s4's address: %p\n", s4.c_str());
    cout << "s3' refcount = " << s3.refcount() << endl;
    cout << "s2' refcount = " << s2.refcount() << endl;
    cout << "s4' refcount = " << s4.refcount() << endl << endl;

    cout << "执行读操作:" << endl;
    cout << "s2[0] = " << s2[0] << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s4 = " << s4 << endl;
    printf("s3's address: %p\n", s3.c_str());
    printf("s2's address: %p\n", s2.c_str());
    printf("s4's address: %p\n", s4.c_str());
    cout << "s3' refcount = " << s3.refcount() << endl;
    cout << "s2' refcount = " << s2.refcount() << endl;
    cout << "s4' refcount = " << s4.refcount() << endl << endl;

    return 0;
}

