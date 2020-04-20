#pragma once

#include "person.h"
/* #include "person.cc" // 这里这么写，就只需要编译client.cc */
using std::cout;
using std::endl;

namespace dec{

class decorator
    :public person
{
public:
    decorator(person * component)
    :_component(component)
    {}

    void show() override
    {
        _component->show();
    }
protected:
    person * _component;
};


class Tshirts
:public decorator
{
public:
    Tshirts(person * component) //创建的时候，就已经把下一步的路铺好了
    :decorator(component)
    {}    

    void show() override
    {
        cout<<"Tshirts ";
        decorator::show();
    }
};


class BigTrouser
:public decorator
{
public:
    BigTrouser(person * component)
    :decorator(component)
    {}

    void show() override
    {
        cout<<"BigTrouser ";
        decorator::show();
    }
};


class Sneakers
:public decorator
{
public:
    Sneakers(person * component)
    :decorator(component)
    {}
      
    void show() override
    {
        cout<<"Sneakers ";
        decorator::show();
    }
};


}//end of namespace dec
