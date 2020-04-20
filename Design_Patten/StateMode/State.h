#pragma once

namespace  status{

class Work;
class State
{
public:
    virtual ~State() {}
    virtual void showStatus(Work) = 0;
};

class MorningState
:public State
{
public:
    void showStatus(Work) override; 
};


class NoonState
:public State
{
public:
    void showStatus(Work) override; 
};


class AfterNoonState
:public State
{
public:
    void showStatus(Work) override; 
};


class EveningState
:public State
{
public:
    void showStatus(Work) override; 
};

class NightState
:public State
{
public:
    void showStatus(Work) override; 
};


}//end of namespace status
