#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Base {
public:
    Base(const char * pstr)
        : _pstr(new char[strlen(pstr) + 1]())
    { cout << "Base(const char *)" << endl; }
    
   virtual //此处的virtual可以把子类的析构函数自动调用  
       ~Base() {
        delete [] _pstr;
        cout << "~Base()" << endl;
    }
private:
    char * _pstr;
};

class Derived
: public Base {
public:
    Derived(const char * pstr, const char * pstr2)
        : Base(pstr)
          , _pstr2(new char[strlen(pstr2) + 1]())

    { cout << "Derived(const char*, const char*)" << endl; }
    
    ~Derived() 
    {
        delete [] _pstr2;
        cout << "~Derived()" << endl;}
private:
    char * _pstr2;
};


void test()
{
    Base * pbase = new Derived("hello", "wuhan");
    delete pbase;
}


int main()
{
    test();
    return 0;
}

