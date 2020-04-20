#include <iostream>
using std::cout;
using std::endl;


class A {
public:
    A() { cout << "A()" << endl; }
    A(int ia): _ia(ia) { cout << "A(int)" << endl; }
    void f() { cout << "A::f()" << endl; }
protected:
    int _ia;
};

class B
: virtual public A { //此处存在虚继承
public:
    B() { cout << "B()" << endl; }
    B(int ia, int ib)
        : A(ia), _ib(ib)
    { cout << "B(int,int)" << endl; }
protected:
    int _ib;
};

class C : public B {
public:
    C(int ia, int ib, int ic)
        : B(ia, ib)
          , _ic(ic)
    { cout << "C(int,int,int)" << endl; }
    void show() const {
        cout << "_ia: " << _ia << endl
            << "_ib: " << _ib << endl
            << "_ic: " << _ic << endl;
    }
private:
    int _ic;
};


void test() {
    C c(10, 20, 30);
    c.show();

}

int main()
{
    test();
    return 0;
}

