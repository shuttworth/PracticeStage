#include "Work.h"
#include "State.h"
#include <iostream>

using namespace status;


void test0()
{
    Work workToday;
    workToday.display();

    workToday.setHour(10);
    workToday.display();

    workToday.setHour(11);
    workToday.display();

    workToday.setHour(12);
    workToday.display();

    workToday.setHour(13);
    workToday.display();

    workToday.setHour(16);
    workToday.display();

    workToday.setHour(18);
    workToday.display();

    workToday.setHour(19);
    workToday.display();

    workToday.setHour(21);
    workToday.display();

    workToday.setHour(23);
    workToday.display();


}


int main()
{
    test0();
    return 0;
}

