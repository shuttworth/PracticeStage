#include <iostream>
#include <string.h>
#include <math.h>
using std::cout;
using std::cin;
using std::endl;


int transfer(int x)
{
    int yushu,p=1,result=0;
    while(1)
    {
        yushu=x%10;
        x=x/10;
        result+=yushu*p;
        p*=2;
        if(x<10)
        {
            result+=yushu*p;
            break;
        }
    }
    return result;
}




int main()
{
    int a;
    cout<<"请输入一个二进制数："<<endl;
    //while(cin>>a&&a)
    while(cin>>a)
    {
        cout<<"得到的十进制数为："<<transfer(a)<<endl;
    }
    return 0;
}

