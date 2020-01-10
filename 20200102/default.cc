#include <iostream>
using std::cout;
using std::endl;

int add(int x,int y=0)
{
    return x+y;
}


int add(int x,int y=4,int z=5)
{
    return x+y+z;
}


void test0()
{
    const int a=10;
    cout<<add(a,1,2)<<endl;
}

int main()
{
    test0();
    //cout<<"add(1,0)="<<add(1,2,3)<<endl;
    return 0;
}

