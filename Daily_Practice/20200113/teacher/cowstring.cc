#include <string.h>
#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

class String
{
	class CharProxy {
	public:
		CharProxy(String & self, size_t idx);
	
		char & operator=(const char & ch);

		friend ostream & operator<<(ostream &, const CharProxy &);

	private:
		String & _self;
		size_t _idx;
	};
public:
    String()
    :_pstr(new char[5]() + 4)
    {
        cout <<"String()" << endl;
        initRefcount();
    }
    String(const char *pstr)
    :_pstr(new char[strlen(pstr) + 5]() + 4)
    {
        cout <<"String(const char *)" << endl;
        strcpy(_pstr, pstr);
        initRefcount();
    }

    String(const String &rhs)
    :_pstr(rhs._pstr)
    {
        cout <<"String(const String &)" << endl;
        increaseRefcount();
    }

    String &operator=(const String &rhs)
    {
        cout << "String &operator=(const String &)" <<endl;
        if (this != &rhs)
        {
            release();
            _pstr = rhs._pstr;
            increaseRefcount();
        }

        return *this;
    }

    CharProxy operator[](size_t idx)
	{
		return CharProxy(*this, idx);
	}

#if 0
    CharProxy operator[](size_t idx)
    {
        if (idx < size())
        {
            if (getRefcount() > 1)
            {
                char *ptmp = new char[size() + 5]() + 4;
                strcpy(ptmp, _pstr);
                decreaseRefcount();
                _pstr = ptmp;
                initRefcount();

            }
            return _pstr[idx];
        }
        else
        {
            static char nullchar = '\0';
            return nullchar;
        }
    }
#endif

    ~String()
    {
        cout << "~String()" << endl;
        release();
    }
public:
    int getRefcount() const
    {
        return *(int *)(_pstr - 4);
    }

    const char *c_str() const
    {
        return _pstr;
    }

    size_t size() const
    {
        return strlen(_pstr);
    }
private:
	//inline函数
    void initRefcount()
    {
        *(int *)(_pstr - 4) = 1;
    }

    void increaseRefcount()
    {
        ++*(int *)(_pstr - 4);
    }

    void decreaseRefcount()
    {
        --*(int *)(_pstr - 4);
    }

    void release()
    {
        decreaseRefcount();
        if (getRefcount() == 0)
        {
            delete [] (_pstr - 4);
            cout << ">>>delete heap data" << endl;
        }

    }

    friend ostream &operator<<(ostream &os, const String &rhs);
	friend ostream & operator<<(ostream & os, const CharProxy & rhs);
private:
    char *_pstr;//指向的是字符串内容本身
};

std::ostream &operator<<(std::ostream &os, const String &rhs)
{
    os << rhs._pstr;
    return os;
}

//全局(普通)函数
ostream & operator<<(ostream & os, const String::CharProxy & rhs)
{
	os << rhs._self._pstr[rhs._idx];
	return os;
}

String::CharProxy::CharProxy(String & self, size_t idx)
: _self(self)
, _idx(idx)
{}


//只关心写操作
char & String::CharProxy::operator=(const char & ch)
{
	size_t sz = _self.size();
    if (_idx < sz)
    {
        if (_self.getRefcount() > 1)
        {
            char *ptmp = new char[sz + 5]() + 4;
            strcpy(ptmp, _self._pstr);
            _self.decreaseRefcount();
            _self._pstr = ptmp;
            _self.initRefcount();

        }
		_self._pstr[_idx] = ch;
        return _self._pstr[_idx];
    }
    else
    {
        static char nullchar = '\0';
        return nullchar;
    }
}


void test()
{
    String s1("hello");
    String s2 = s1;

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;

    cout << "s1's refcount = " << s1.getRefcount() << endl;
    cout << "s2's refcount = " << s2.getRefcount() << endl;
    
    printf("s1's address: %p\n", s1.c_str());
    printf("s2's address: %p\n", s2.c_str());

    cout << endl;
    String s3 = "world";
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;

    cout << "s1's refcount = " << s1.getRefcount() << endl;
    cout << "s2's refcount = " << s2.getRefcount() << endl;
    cout << "s3's refcount = " << s3.getRefcount() << endl;
    
    printf("s1's address: %p\n", s1.c_str());
    printf("s2's address: %p\n", s2.c_str());
    printf("s3's address: %p\n", s3.c_str());

    cout << endl;
    s3 = s1;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;

    cout << "s1's refcount = " << s1.getRefcount() << endl;
    cout << "s2's refcount = " << s2.getRefcount() << endl;
    cout << "s3's refcount = " << s3.getRefcount() << endl;
    
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

    cout << "s1's refcount = " << s1.getRefcount() << endl;
    cout << "s2's refcount = " << s2.getRefcount() << endl;
    cout << "s3's refcount = " << s3.getRefcount() << endl;
    
    printf("s1's address: %p\n", s1.c_str());
    printf("s2's address: %p\n", s2.c_str());
    printf("s3's address: %p\n", s3.c_str());

    cout << endl;
    cout << "对s1[0] 执行读操作之后 :" << endl;
    cout << "s1[0] = " << s1[0] << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;

    cout << "s1's refcount = " << s1.getRefcount() << endl;
    cout << "s2's refcount = " << s2.getRefcount() << endl;
    cout << "s3's refcount = " << s3.getRefcount() << endl;
    
    printf("s1's address: %p\n", s1.c_str());
    printf("s2's address: %p\n", s2.c_str());
    printf("s3's address: %p\n", s3.c_str());

}

void test1()
{
	String s1("hello");

	String s2("hello");

	s1[0] = 'X';
}

int main(int argc, char **argv)
{
    test();
    return 0;
}

