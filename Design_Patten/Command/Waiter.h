#pragma once
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Workers
{
public:
    void sellBarbecue()
    {
        if(_barbecue>0){
            --_barbecue;
            cout<<"barbecue is coming for customers ,left :"<<_barbecue<<endl;
        }else{
            cout<<"Workers:No barbecue left"<<endl;
        }
    }

    void sellBeers()
    {
        if(_beers>0){
            --_beers;
            cout<<"beers is coming for customers ,left :"<<_beers<<endl;
        }else{
            cout<<"Workers:No beers left"<<endl;
        }
    }

    void preBarbecue()
    {
        ++_barbecue;
        cout<<"barbecue is preparing ,now the amount : "<<_barbecue<<endl;
    }

    void preBeers()
    {
        ++_beers;
        cout<<"beers is preparing ,now the amount : "<<_beers<<endl;
    }

    int getBarbecue()
    {
        return _barbecue;
    }
    int getBeers()
    {
        return _beers;
    }

private:
    int _barbecue;
    int _beers;
};


class Command
{
public:
    Command(Workers * worker)
    :_worker(worker)
    {}

    virtual void excute() = 0;
    virtual ~Command() {}; //析构是需要这么写的,大括号不能够少

    Workers * getWorkers()
    {
        return _worker;
    }
    
    virtual string getName()
    {
        return "Command";
    }

protected:
    Workers * _worker;
};

class barbecueCommand
:public Command
{
public:
    barbecueCommand(Workers* worker)
    :Command(worker)
    {}

    void excute() override
    {
        _worker->sellBarbecue();
    }
    string getName() override
    {
        return "barbecueCommand";
    }
};

class beerCommand
:public Command
{
public:
    beerCommand(Workers* worker)
    :Command(worker)
    {}

    void excute() override
    {
        _worker->sellBeers();
    }
    string getName() override
    {
        return "beerCommand";
    }
};



class Waiter
{
public:
    void setOrder(Command * comm)
    {
        if(comm->getWorkers()->getBarbecue()==0&&comm->getName()=="barbecueCommand")
        {//typeid也可以实现效果
            cout<<"No barbecue left"<<endl;
        }
        else if(comm->getWorkers()->getBeers()==0&&comm->getName()=="beerCommand")
        {
            cout<<"No beers left"<<endl;
        }
        else {
            _vec.push_back(comm);
        }
    }

    void notifyAll()
    {
        for(auto it:_vec)
        {
            it->excute();
        }
    }


private:
    vector<Command*> _vec;
};

