#include<iostream>
using namespace std;

class A{
public:
    void func();
public:
    int n=30;
};

void A::func(){ cout<<"c.biancheng.net"<<endl; }

class B: public A{
public:
    int n=20;
    int m;
};

class C: public B{
public:
    int n=10;
    int x;
};

int main(){
    C obj;
    cout<<"n="<<obj.n<<endl;
    obj.func();
    cout<<sizeof(C)<<endl;

    return 0;
}
