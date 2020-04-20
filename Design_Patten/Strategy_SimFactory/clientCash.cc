#include "CashContext.cc"

using namespace stg;
using namespace std;

/* typedef "正常收费" symbol1; */


void test0()
{
    CashContext ct1("正常收费");
    cout<<"正常收费500 = "<<ct1.getResult(500)<<endl;

    CashContext ct2("满300减100");
    cout<<"满300减100,消费500 = "<<ct2.getResult(500)<<endl;

    CashContext ct3("满300减100");
    cout<<"满300减100,消费200 = "<<ct3.getResult(200)<<endl;

    CashContext ct4("打8折");
    cout<<"打8折,消费500 = "<<ct4.getResult(500)<<endl;

    CashContext ct5("打8折");
    cout<<"打8折,消费100 = "<<ct5.getResult(100)<<endl;
}



int main()
{
    test0();
}
