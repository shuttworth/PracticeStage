#include <iostream>

using std::cout;
using std::endl;

void test0()
{
    int i=1;
    int j;//i 行，j 列
    for(;i<10;i++)
    {
        for(j=1;j<=i;j++)
        {
            cout<<i<<"*"<<j<<"="<<i*j<<"  ";
        }
        cout<<endl;
    }
}

int main()
{
    test0();
    return 0;
}

