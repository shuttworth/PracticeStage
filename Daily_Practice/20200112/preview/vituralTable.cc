#include <iostream>
using std::cout;
using std::endl;

class Base {
public:
    Base(long data1): _data1(data1) {}
    virtual
        void func1() { cout << "Base::func1()" << endl; }
    virtual
        void func2() { cout << "Base::func2()" << endl; }
    virtual
        void func3() { cout << "Base::func3()" << endl; }
private:
    long _data1;
};

class Derived
: public Base {
public:
    Derived(long data1, long data2)
        : _data1(data1) //为何无法通过
          , _data2(data2) {}
    virtual void func1() { cout << "Derived::func1()" << endl; }
    virtual void func2() { cout << "Derived::func2()" << endl; }
private:
    long _data2;

};

void test()
{
    Derived derived(10, 100);
    long ** pVtable = (long **)&derived;
    typedef void(* Function)();
    for(int idx = 0; idx < 3; ++idx) {
        Function f = (Function)pVtable[0][idx];
        f();
    }
}


int main()
{
    test();
    return 0;
}

