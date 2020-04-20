#include <iostream>
#include <stdio.h>

using std::cout;
using std::endl;
using std::cin;

int main(){
    int num=0;
    cout<<"请输入一个十进制的数"<<endl;
    while(cin>>num)
    {
        //scanf("%d",&num);
        cout<<"得到的十六进制的数"<<endl;
        printf("%x",num);//这个就是以16进制输出了
        cout<<endl;
    }

        return 0;
}

