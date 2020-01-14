#include<string.h> 
#include <iostream>

using std::cout;
using std::endl;
using std::cerr;

class String {
public:
    String()
    {
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
        cout<<"String(const string & rhs)"<<endl;
    }

    ~String()
    {
        if(_pstr)
        {
            delete [] _pstr;
            _pstr =nullptr;
            cout<<"~string()"<<endl;
        }
    }


    String &operator=(const String &rhs)
    {
        if(_pstr!=rhs._pstr)
        {
            delete [] _pstr;
            _pstr=new char[strlen(rhs._pstr)+1]();
            strcpy(_pstr,rhs._pstr);
            cout<<"String &operator=(const String &rhs)"<<endl;
        }
        return * this;
    }

    void print()
    {
        cout<<_pstr<<endl;
    }

    String &operator=(const char * str1)
    {
        if(_pstr!=str1)
        {
            delete [] _pstr;
            _pstr=new char[strlen(str1)+1]();
            strcpy(_pstr,str1);
            cout<<"String &operator=(const char * str1)"<<endl;
        }
        return * this;
    }

    String  & operator+=(const String & str1)
    {
        strcat(_pstr,str1._pstr);
        // _pstr=strcat(_pstr,str1._pstr);
        return *this;
    }

    String &operator+=(const char * str2)
    {
        strcat(_pstr,str2);
        return * this;
    }

    char &operator[](std::size_t index)
    {
        if(index >=0 && index < strlen(_pstr)) {
            return _pstr[index];
        } else {
            static char nullchar = '\0';
            cerr << "下标越界！\n";
            return nullchar;
        }
    }


    const char &operator[](std::size_t index) const
    {
        return _pstr[index];
    }

    std::size_t size() const
    {
        return strlen(_pstr);
    }

    const char* c_str() const
    {
        return _pstr;
    }

    friend bool operator==(const String &lhs, const String &rhs);

    friend bool operator!=(const String &, const String &);

    friend bool operator<(const String &, const String &);
    friend bool operator>(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend bool operator>=(const String &, const String &);

    friend std::ostream &operator<<(std::ostream &os, const String &s);
    friend std::istream &operator>>(std::istream &is, String &s);

    char * getpstr() const
    {
        return _pstr;
    }

private:
    char * _pstr;

};

bool operator==(const String &lhs, const String &rhs)
{
    return !strcmp(lhs._pstr,rhs._pstr);
}

bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs==rhs);
}

bool operator<(const String &lhs, const String &rhs)
{
    if(strcmp(lhs._pstr,rhs._pstr)<0)
    {
        return 1;
    }
    else return 0;
}

bool operator>(const String &lhs, const String &rhs)
{
    if(strcmp(lhs._pstr,rhs._pstr)>0)
    {
        return 1;
    }
    else return 0;
}

bool operator<=(const String &lhs, const String &rhs)
{
    if(strcmp(lhs._pstr,rhs._pstr)<=0)
    {
        return 1;
    }
    else return 0;
}


bool operator>=(const String &lhs, const String &rhs)
{
    if(strcmp(lhs._pstr,rhs._pstr)>=0)
    {
        return 1;
    }
    else return 0;
}

std::ostream &operator<<(std::ostream &os, const String &s)
{
    os<<s._pstr;
       // <<endl;
    return os;
}

std::istream &operator>>(std::istream &is, String &s)
{
    is>>s._pstr;
       // <<endl;
    return is;
}




String operator+(const String &lhs, const String &rhs)
{
    strcat(lhs.getpstr(),rhs.getpstr());
    return lhs;
}
String operator+(const String &lhs, const char * s1)
{
    strcat(lhs.getpstr(),s1);
    return lhs;
}
String operator+(const char *s2, const String &rhs)
{
    String temp = String(s2);
    strcat(temp.getpstr(),rhs.getpstr());
    return temp;
}


int main()
{
    String st1("hello");
    String st2=st1;
    String st3="good";
    st3.print();
    st3=st2;
    st1.print();
    st2.print();
    st3.print();

    st3="fine";
    st3.print();
    String st4="fine";
    cout<<(st3==st4)<<endl;
    cout<<(st3==st1)<<endl;
    return 0;
}
