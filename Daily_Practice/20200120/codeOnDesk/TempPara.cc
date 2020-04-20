#include <iostream>

using std::cout;
using std::endl;

template <class...Args>
void printPara(Args...args)
{
    cout<<"sizeof...(args): "<<sizeof...(args)<<endl;
    cout<<"sizeof...(Args): "<<sizeof...(Args)<<endl;
}


template<class T >
void display(T t)
{
    cout<<"  "<<t<<endl;
}


template<class T ,class ...Args> //三处的写法
//class ...Args | Args ...args | args ...
void display(T t,Args...args)
{
    cout<<"  "<<t<<endl;
    display(args...);
}


int main()
{
    display("hello",1,2,3);
    return 0;
}

