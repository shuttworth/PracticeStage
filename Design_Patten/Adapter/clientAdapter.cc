#include "adapter.h"
#include <memory>
using std::unique_ptr;


void test0()
{
    unique_ptr<player> player1(new Forwards("Lebron james"));
    unique_ptr<player> player2(new Center("Shark"));
    unique_ptr<player> player3(new Forwards("Kobe"));
    unique_ptr<player> trans(new Translator("姚明"));

    player1->Attack();
    player2->Attack();
    player3->Attack();

    trans->Attack();
    trans->Defense();
}


int main()
{
    test0();
    return 0;
}

