#include <iostream>
#include <stdio.h>

using std::cout;
using std::endl;
using std::cin;

int main(){
    int num=0;
    cout<<"请输入一个十六进制的数"<<endl;
    //while(cin>>num)
    while(scanf("%x",&num)!=EOF)
    {
        //scanf("%x",&num);
        cout<<"得到的十进制的数"<<endl;
        printf("%d",num);//这个就是以16进制输出了
        cout<<endl;
    }

        return 0;
}

