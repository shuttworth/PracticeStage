#include <iostream>

using std::cout;
using std::endl;
void test0()
{
    union array{
        int a=1;
        char b[4];
    };

    union array t1;

    int x1=t1.b[0];
    cout<<x1<<endl;

    int x2=t1.b[1];
    cout<<x2<<endl;

    int x3=t1.b[2];
    cout<<x3<<endl;

    int x4=t1.b[3];
    cout<<x4<<endl;
    

}








int main()
{
    test0();
    return 0;
}

