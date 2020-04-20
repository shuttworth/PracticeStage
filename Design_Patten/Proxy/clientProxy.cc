#include "proxy.cc"

using namespace pro;


void test0()
{
    girl mm("gena");
    Proxy proxy(mm);
    proxy.GiveDolls();
    proxy.GiveFlowers();
    proxy.GiveChocolate();
}



int main()
{
    test0();
    return 0;
}
