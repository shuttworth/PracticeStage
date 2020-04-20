#include "Action.h"


void test0()
{
    ManagerStuct ceo;
    Person * per1 = new Man();
    Person * per2 = new Woman();
    ceo.addPerson(per1);
    ceo.addPerson(per2);

    Action * act1 = new SuccessAction();
    Action * act2 = new SadAction();

    ceo.excute(act1);
    ceo.excute(act2);
    
    delete per1;
    delete per2;


}



int main()
{
    test0();
    return 0;
}

