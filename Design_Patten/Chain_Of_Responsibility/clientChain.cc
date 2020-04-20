#include "Manager.h"



void test0()
{
     Request * req1 = new Request();
     req1->setCategory("请假");
     req1->setContent("小王请假");
     req1->setAmount(3);

     Request * req2 = new Request();
     req2->setCategory("请假");
     req2->setContent("小李请假");
     req2->setAmount(6);

     Request * req3 = new Request();
     req3->setCategory("请假");
     req3->setContent("小牛请假");
     req3->setAmount(10);

     Request * req4 = new Request();
     req4->setCategory("涨工资");
     req4->setContent("小徐想涨工资");
     req4->setAmount(1200);

    Manager * mag1 = new CommonManager("李经理");
    Manager * mag2 = new ChiefManager("王总监");
    Manager * mag3 = new GeneralManager("郝董事长");

    mag1->setHeadManager(mag2);
    mag2->setHeadManager(mag3);

    mag1->handleRequest(req1);
    mag1->handleRequest(req2);
    mag1->handleRequest(req3);
    mag1->handleRequest(req4);

    delete req1;
    delete req2;
    delete req3;
    delete req4;

    delete mag1;
    delete mag2;
    delete mag3;

}



int main()
{
    test0();
    return 0;
}

