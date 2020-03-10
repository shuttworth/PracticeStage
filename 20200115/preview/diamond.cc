#include <iostream>
using std::cout;
using std::endl;

class B{
public:
    B() : _ib(10), _cb('B') { cout << "B()" << endl; }
    B(int ib, char cb)
        : _ib(ib), _cb(cb){ cout << "B(int,char)" << endl; }
    virtual
        void f() { cout << "B::f()" << endl; }
    //virtual
    void Bf() { cout << "B::Bf()" << endl; }
private:
    int _ib;
    char _cb;
};

class B1 : virtual public B {
public:
    B1() : _ib1(100), _cb1('1') {}
    B1(int ib, char ic, int ib1, char cb1)
        : B(ib, ic)
          , _ib1(ib1)
          , _cb1(cb1)
    { cout << "B1(int,char,int,char)" << endl; }
    virtual
        void f() { cout << "B1::f()" << endl; }
    //virtual
    void f1() { cout << "B1::f1()" << endl; }
    //virtual
    void Bf1() { cout << "B1::Bf1()" << endl; }
private:
    int _ib1;
    char _cb1;
};

class B2 : virtual public B {
public:
    B2() : _ib2(1000), _cb2('2') {}
    B2(int ib, char ic, int ib2, char cb2)
        : B(ib, ic)
          , _ib2(ib2)
          , _cb2(cb2)
    { cout << "B2(int,char,int,char)" << endl; }
    //virtual
    void f() { cout << "B2::f()" << endl; } 
    virtual
        void f2() { cout << "B2::f2()" << endl; }
    //virtual
    void Bf2() { cout << "B2::Bf2()" << endl; }
private:
    int _ib2;
    char _cb2;
};

class D
: public B1
    , public B2 {
    public:
        D() : _id(10000), _cd('3') {}
        D(int ib1, char cb1,
          int ib2, char cb2,
          int id, char cd)
            : B1(ib1, cb1,id,cd)
              , B2(ib2, cb2,id,cd)
              , _id(id)
              , _cd(cd)
        { cout << "D(...)" << endl; }
        virtual
            void f() { cout << "D::f()" << endl; }
        //virtual
        void f1() { cout << "D::f1()" << endl; }
        //virtual
        void f2() { cout << "D::f2()" << endl; }
        //virtual
        void Df() { cout << "D::Df()" << endl; }
    private:
        int _id;
        char _cd;
    };

void test(void) {
    D d;
    cout << sizeof(d) << endl;
}




int main()
{
    test();
    return 0;
}

