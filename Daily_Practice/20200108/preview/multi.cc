#include <iostream>
using namespace std;

//基类Base
class Base{
public:
    virtual void func();
    virtual void func(int);
};
void Base::func(){
    cout<<"void Base::func()"<<endl;
}
void Base::func(int n){
    cout<<"void Base::func(int)"<<endl;
}

//派生类Derived
class Derived: public Base{
public:
    void func();
    void func(char *);
};
void Derived::func(){
    cout<<"void Derived::func()"<<endl;
}
void Derived::func(char *str){
    cout<<"void Derived::func(char *)"<<endl;
}

int main(){
    Base *p = new Derived();
    p -> func();  //输出void Derived::func() func()被成员遮蔽了，用的派生类的
    p -> func(10);  //输出void Base::func(int) ,因为没有被成员遮蔽，还是用的基类得到func（）
    //p -> func("http://c.biancheng.net");  //compile error
    //基类的指针只能访问从基类继承过去的功能，不能访问派生类新增的成员
    return 0;
}
