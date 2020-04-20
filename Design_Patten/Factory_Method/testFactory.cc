#include "Factory.h"

using namespace Product;


void test0()
{
    //先创造一个工厂，再由工厂生产产品出来
    iFactory * oper = new UndergraduateFactory();
    iFactory * oper1 = new VolunteersFactory();
    LeiFeng * lei = oper->createLeiFeng();
    LeiFeng * leon = oper1->createLeiFeng();

    /* lei->wash(); */
    //下面的内容如果封装了，那么就是建造者模式
    lei->buyRice();
    lei->sweep();
    lei->wash();

    leon->buyRice();
    leon->sweep();
    leon->wash();

}



int main()
{
    test0();
    return 0;
}
