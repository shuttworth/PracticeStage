#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>

using std::vector;
using std::endl;
using std::cout;
using std::string;



class Action;
class Person
{
public:
    virtual void accept(Action *) = 0;

    virtual ~Person() {}
};

class Action
{
public:
    virtual ~Action() {}

    virtual void getManConclu(Person *) = 0;
    virtual void getWomanConclu(Person *) = 0;

private:

};



class Woman:
public Person
{
public:
    void accept(Action * act) override
    {
        act->getWomanConclu(this);
    }
};

class Man:
public Person
{
public:
    void accept(Action * act) override
    {
        act->getManConclu(this);
    }
};


class SuccessAction
:public Action
{
public:
    void getManConclu(Person * person) override
    {
        cout<<"when "<<typeid(*person).name()<<" success ,a woman is helping him all the time in the back"<<endl;       
    }
    void getWomanConclu(Person * person) override
    {
        cout<<"when "<<typeid(*person).name()<<" success ,a man is with her always"<<endl;       
    }

};


class SadAction
:public Action
{
public:
    void getManConclu(Person * person) override
    {
        cout<<"when "<<typeid(*person).name()<<" is sad , games and sports are good choices for them"<<endl;       
    }
    void getWomanConclu(Person * person) override
    {
        cout<<"when "<<typeid(*person).name()<<" is sad ,close friends are neccessary"<<endl;       
    }

};


class ManagerStuct
{
public:
    void addPerson(Person * pers)
    {
        _vec.push_back(pers);
    }

    void excute(Action * act)
    {
        for(auto & it:_vec )
        {
            it->accept(act);
        }
    }

private:
    vector<Person * >_vec;
};


