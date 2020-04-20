#include "Work.h"
#include "State.h"

namespace  status{


    Work::Work() 
    :_curstate(new MorningState())
    ,_hour(9)
    ,_isFinished(false)
    {}


double Work::getHour() const
{
    return _hour;
}

bool Work::TaskFinished() const
{
    return _isFinished;
}

void Work::setState(State * curstate)
{
    _curstate = curstate;
}

void Work::display() const
{
    _curstate->showStatus(*this);
}

void Work::setHour(double hour) 
{
    _hour = hour;
}




}//end of namespace status
