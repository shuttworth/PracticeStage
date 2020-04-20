#include "decorator.h"

using namespace dec;

void test0()
{
    person * wsa = new person("汪寿安"); 
    cout<<"第一种装扮\n";

    Sneakers * pqx = new Sneakers(wsa);
    Tshirts * dtx = new Tshirts(pqx);
    BigTrouser * kk = new BigTrouser(dtx);

    kk->show();

}



int main()
{
    test0();
    return 0;
}

