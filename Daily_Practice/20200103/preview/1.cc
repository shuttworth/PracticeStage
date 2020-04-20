#include <iostream>
using namespace std;


int main()
{
    int a=2;
    int & ref = a;
    cout<<"a address="<<&a<<endl;
    cout<<"ref="<<ref<<endl;
    cout<<"&ref="<<&ref<<endl;
    return 0;
}

