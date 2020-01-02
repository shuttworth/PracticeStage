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

int count1(int n)
{
    int count = 0;
    int flag = 1;
    while (flag != 0) {
        if ((n & flag) != 0) {
            count++;
        }
        flag = flag << 1;
    }
    return count;
}


int main()
{
    int a;
    cout<<"请输入一个十进制数："<<endl;
    while(cin>>a&&a)
    {

        if(a>=0) cout<<"得到的二进制数为："<<transfer(a)<<endl;
        cout<<"1的个数为"<<count1(a)<<endl;

        /*
           else {
           int k=transfer(-a);
        //int array[SIZE] = { 1, 2, 3, 4, 5, 6,1, 2, 3, 4, 5 };
        cout<<"得到的二进制数为："<<~k+1<<endl; //卡在这一步，出问题了
        }
        }
        */

    }
    return 0;
}
