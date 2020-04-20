#ifndef OBSERVER_H
#define OBSERVER_H

#include <list>
#include <iostream>
#include <string>
#include "Subject.h"

//Observer,抽象观察者
class Observer
{
protected:
    std::string name;
    Subject* sub;
public:
    Observer();
    Observer(std::string name,Subject* sub);
    virtual void Update();
    bool operator==(const Observer&)const;
    virtual ~Observer(){}
};

//ConcreteObserver,具体观察者，股票观察者
class StockObserver:public Observer
{
public:
    StockObserver();
    StockObserver(std::string name,Subject* sub);
    void Update();
};


//ConcreteObserver，具体观察者，NBA观察者
class NBAObserver:public Observer
{
public:
    NBAObserver();
    NBAObserver(std::string name,Subject* sub);
    void Update();
};

#endif

