#include <iostream>

using std::cout;
using std::endl;

//模板的一种用法
template <typename T>
T add(T x,T y)
{
    cout<<" T add(T x,T y) "<<endl;
    return x+y;
}

template <typename T>
T add(T x,T y,T z)
{
    cout<<" T add(T x,T y,T z) "<<endl;
    return x+y+z;
}


//函数模板和普通函数是可以重载的
//而且普通函数的执行会优先于函数模板
int add(int x,int y)
{
    cout<<"int add(int x,int y)"<<endl;
    return x+y;
}


int main()
{
    int a1=3,b1=4;
    float a2=1.1,b2=1.2;
    cout<<"add(a1,b1) = "<<add(a1,b1)<<endl; //隐式实例化
    cout<<"add(a2,b2) = "<<add(a2,b2)<<endl;
    cout<<"add(a2,b2) = "<<add<float>(a2,b2)<<endl; //显式实例化
    return 0;
}

