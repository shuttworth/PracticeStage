#pragma once
#include "Notifier.h"
#include <iostream>
#include <string.h>
using std::string;
using std::cout;
using std::endl;

namespace ob{

class Observer
{
public:
    Observer(string name,Notifier * noti) 
    :_name(name)
    ,_noti(noti) 
    {}

    virtual ~Observer() {}
    virtual void update() = 0;

protected:
    string _name;
    Notifier * _noti;
};


class StockObserver
:public Observer
{
public:
    StockObserver(string name,Notifier * noti)
    :Observer(name,noti)
    {}

    void update() override;
};



class LOLObserver
:public Observer
{
public:
    LOLObserver(string name,Notifier *   noti)
    :Observer(name,noti)
    {}

    void update() override;
};





}//end of namespace ob
