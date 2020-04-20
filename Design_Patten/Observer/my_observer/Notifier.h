#pragma once

#include <list>
#include <string.h>
#include <iostream>
using std::string;
using std::list;

namespace ob{

class Observer;
class Notifier
{
public:

    virtual void attach(Observer *) = 0;
    virtual void detach(Observer *) = 0;
    virtual void notifyAll() = 0;
    virtual void setStatus(string) = 0;
    virtual string getStatus() = 0;


    virtual ~Notifier() {}

};

class BossNotifier
:public Notifier
{
public:

    void attach(Observer * ob) override;

    void detach(Observer * ob) override;

    void notifyAll() override;
    
    void setStatus(string status) override;
        
    string getStatus() override;

private:
    list<Observer*> _listNotify;
    //通知者内部定义了请求观察的观察者队列，有情况变化会挨个通知


    string _status;

};



}//end of namespace ob
