#include <iostream>
using std::cout;
using std::endl;

void test0()
{
    int i,j;//行
    for(i=1;i<=5;i++)
    {
        for(j=0;j<=5-i;j++)
        {
            cout<<"  ";
        }
        for(j=1;j<=i;j++)
        {
            cout<<"*   ";
        }
        cout<<endl;
    }

}


int main()
{
    test0();
    return 0;
}

