#include <iostream>
using std::cout;
using std::endl;

class Base {
public:
    Base(int m)
        : _member(m)
    { cout << "Base(int)" << endl; }
    
    void func(int x)
    { cout << "Base::func(int)" << endl; }
    
   virtual  ~Base() 
    { 
        cout << "~Base()" << endl; 
    }
protected:
    int _member;
};

class Derived
: public Base {
public:
    Derived(int m1, int m2)
        : Base(m1)
          , _member(m2)
    { cout << "Derived(int, int)" << endl; }
    
    void func(int *) 
    {
        cout << "_member: " << _member << endl;
        cout << "Derived::func(int*)" << endl;
    }
    ~Derived() { cout << "~Derived()" << endl; }
private:
    int _member;
};

int num =5;
int * point =&num;

//并不知道如何把隐藏这个情况测试出来
int main()
{
    //Base * p1=new Derived(3,4);
    //p1->func(10);
    Derived * p2 = new Derived(6,7);
    p2->func(point);
    delete p2;
    return 0;
}

