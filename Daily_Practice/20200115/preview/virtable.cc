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
        //:_data1(data1),
        :Base(data1)
         ,_data2(data2) {}
    virtual void func1() { cout << "Derived::func1()" <<
        endl; }
    virtual void func2() { cout << "Derived::func2()" <<
        endl; }
private:
    long _data2;
};


void test()
{
    Derived derived(10, 100);
    long ** pVtable = (long **)&derived; //这段代码要听一下
    typedef void(* Function)(); //函数对象的创建：返回值为void，不传参的对象都可以被Function创建的类调用
    for(int idx = 0; idx < 3; ++idx) 
    {
        Function f = (Function)pVtable[0][idx];
        f();
    }
//由打印结果可知，虚表真的存在
}

    int main()
    {
        test();
        return 0;
    }

