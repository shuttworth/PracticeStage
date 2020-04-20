#include "Brand.h"


void test0()
{
    PhoneSoftware * psw1 = new GameSoftware(); 
    PhoneSoftware * psw2 = new AddressBook(); 
    Brand * br = new PhoneBrand1("APPLE");
    br->addSoftWare(psw1);
    br->addSoftWare(psw2);
    br->runSoftware();
    delete psw1;
    delete psw2;
    delete br;
}



int main()
{
    test0();
    return 0;
}

