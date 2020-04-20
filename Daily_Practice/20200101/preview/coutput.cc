#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str="http://c++.coding.com";
    for(int i=str.length()-1;i>=0;i--)
//两者都是求字符串的长度,但strlen( )的参数必须是char* ;
//而 str.length( )是string类对象str调用的成员函数,
//所以它们用在不同的地方;
    {
       // cout.put(str[i]);
        putchar(str[i]);
    }
    cout<<endl;
    return 0;
}

