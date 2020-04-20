#include "State.h"
#include "Work.h"
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

namespace status
{

void MorningState::showStatus(Work curwork)
{
    if(curwork.getHour()<12)
    {
        cout<<"Now is "<<curwork.getHour()<<" 早上工作 高效精神 "<<endl;
    }

    else{
        curwork.setState(new NoonState());
        curwork.display();
    }
}

void NoonState::showStatus(Work curwork)
{
    if(curwork.getHour()<14)
    {
        cout<<"Now is "<<curwork.getHour()<<" 中午休息 养足精神 "<<endl;
    }

    else{
        curwork.setState(new AfterNoonState());
        curwork.display();
    }
}


void AfterNoonState::showStatus(Work curwork)
{
    if(curwork.getHour()<18)
    {
        cout<<"Now is "<<curwork.getHour()<<" 下午工作 重新出发 "<<endl;
    }

    else{
        curwork.setState(new EveningState());
        curwork.display();
    }
}

void EveningState::showStatus(Work curwork)
{
    if(curwork.getHour()<22)
    {
        cout<<"Now is "<<curwork.getHour()<<" 晚上工作 抓紧收工 "<<endl;
    }

    else{
        curwork.setState(new NightState());
        curwork.display();
    }
}

void NightState::showStatus(Work curwork)
{
    if(curwork.getHour()<24)
    {
        cout<<"Now is "<<curwork.getHour()<<" No Working now!! 996.icu "<<endl;
    }

    /* else{ */
    /*     curwork.setState(new NoonState()); */
    /*     curwork.display(); */
    /* } */
}




}//end of namespace status
