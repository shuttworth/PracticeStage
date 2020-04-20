#pragma once
/* #include "State.h" */

namespace status{

class State;
class Work
{
public:
    Work();

    void setHour(double);
    double getHour() const;
    /* { */
    /*     return _hour; */
    /* } */

    bool TaskFinished() const;
    /* { */
    /*     return _isFinished; */
    /* } */

    void setState(State * curstate);

    void display() const;

private:
    State * _curstate;
    double _hour;
    bool _isFinished;
};





}//end of namespace status

