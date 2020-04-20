#include <iostream>
#include <string.h>
using std::cout;
using std::cin;
using std::endl;


int main()
{
    char * a =new char[100]();
    while(cin>>a)
    {
    int len=strlen(a);
    for(int i=0;i<len;i++)
    {
        printf("%c",a[i]-32);
    }
    cout<<endl;
   // cout<<a<<endl;
    }
    return 0;
    delete  [] a;
}

