#include "Waiter.h"


void test0()
{
    Workers * worker = new Workers();
    Waiter girlwaiter;
    worker->preBarbecue();
    worker->preBarbecue();
    worker->preBeers();
    worker->preBeers();
    worker->preBeers();

    Command * comm1 = new barbecueCommand(worker);
    Command * comm2 = new barbecueCommand(worker);
    Command * comm3 = new barbecueCommand(worker);

    Command * comm4 = new beerCommand(worker);
    Command * comm5 = new beerCommand(worker);
    Command * comm6 = new beerCommand(worker);
    Command * comm7 = new beerCommand(worker);

    girlwaiter.setOrder(comm1);
    girlwaiter.setOrder(comm2);
    girlwaiter.setOrder(comm3);
    girlwaiter.setOrder(comm4);
    girlwaiter.setOrder(comm5);
    girlwaiter.setOrder(comm6);
    girlwaiter.setOrder(comm7);

    girlwaiter.notifyAll();

    /* delete worker; */
    /* delete comm1; */
    /* delete comm2; */
    /* delete comm3; */
    /* delete comm4; */
    /* delete comm5; */
    /* delete comm6; */
    /* delete comm7; */

}




int main()
{
    test0();
    return 0;
}

