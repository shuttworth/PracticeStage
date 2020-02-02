#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;
int Fib(int n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else return Fib(n-1)+Fib(n-2);
}

//0 1 1 2 3 5 8 13 21  Fibonacci

int main()
{
    int num;
    while(scanf("%d",&num)!=EOF)
    {
        cout<<"Fib("<<num<<") ="<<Fib(num)<<endl;
    }
    system("pause");
    return 0;//告诉控制台，函数正常退出;return 1则是异常退出
}

