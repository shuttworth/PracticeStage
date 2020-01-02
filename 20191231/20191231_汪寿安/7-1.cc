#include <iostream>
#include <string.h>
#include <math.h>
using std::cout;
using std::cin;
using std::endl;


int transfer(int x)
{
    int p=1,y=0,yushu;
    while(1)
    {
        yushu=x%2;
        x/=2;
        y+=yushu*p;
        p*=10;
        if(x<2)
        {
            y+=x*p;
            break;
        }
    }
    return y;
}


int transfer1(int x)
{
    int y,r=0,p=1;//y 余数 w 位数 r 结果
    while(1)
    {
        //5/2=2 5%2=1 
        //2/2=1 2%2=0 
        //1/2=0 1%2=1 
        //5=101
        x=x/2;
        y=x%2;
        r+=y*p;
        p*=10;
        if(x<2)
        {   
            r=r+y*p;
            break;
        }
    }
    return r;           


}


int main()
{
    int a;
    cout<<"请输入一个十进制数："<<endl;
    while(cin>>a&&a)
    {   
        if(a>=0) cout<<"得到的二进制数为："<<transfer(a)<<endl;
        else {
            int k=transfer(-a);
            cout<<"k="<<k<<endl;
            cout<<"得到的二进制数为："<<~k+1<<endl; // ~按位取反符，有点问题，直接得到十进制结果了
        }
    }
    return 0;
}

