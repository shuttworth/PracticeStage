#include "Website.h"
#include <memory>
using std::unique_ptr;


void test0()
{
    User *  user1 = new User("gina");
    User *  user2 = new User("oliver");
    User *  user3 = new User("kingdom");
    User *  user4 = new User("anna");


    WebFacory fac;
    Website * web1 = fac.createWeb("C++ reference");
    web1->Server(user1);

    Website * web2 = fac.createWeb("CSAPP");
    web2->Server(user1);
    web2->Server(user2);

    Website * web3 = fac.createWeb("C++ reference");
    web3->Server(user3);
    web3->Server(user4);

    //delete user1;

}



int main()
{
    test0();
    return 0;
}

