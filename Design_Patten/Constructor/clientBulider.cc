#include "Director.h"
/* #include <memory> */
/* #include <iostream> */
using namespace bulid;

void test0()
{
    Builder * ptr1 = new HomeBuilderA("wade","james");
    Builder * ptr2 = new HomeBuilderB("jim","kate");
    Director dir1(ptr1);
    Director dir2(ptr2);
    dir1.createBuilder();
    dir2.createBuilder();
    delete ptr1;
    delete ptr2;
}



int main()
{
    test0();
    return 0;
}

