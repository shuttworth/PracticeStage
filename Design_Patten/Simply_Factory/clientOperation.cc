#include "OperationFactory.cc"
/* #include <iostream> */

using namespace std;
using namespace op;

void test0()
{
    while(1){
        cout<<"please input two numbers"<<endl;
        double a,b;
        cin>>a>>b;//空格隔开？

        cout<<"please input a operator like:"
            <<" + - * /"<<endl;
        char c;
        cin>>c;
        /* cout<<"c is "<<c<<endl; */
        Operation * oper = OperationFactory::createOperation(a,b,c);

        cout<<"result is:"<<oper->GetResult()<<endl;
        cout<<endl;

    }
}



int main()
{
    test0();
}
