#pragma once
#include <iostream>
#include <string.h>
using std::endl;
using std::cout;
using std::string;


class Request
{
public:
    void setCategory(string category)
    {
        _category = category;
    }

    void setContent(string content)
    {
        _content = content;
    }

    void setAmount(int amount)
    {
        _amount = amount;
    }

    string getCategory()
    {
        return _category;
    }

    string getContent()
    {
        return _content;
    }

    int getAmount()
    {
        return _amount;
    }

private:
    string _category;
    string _content;
    int _amount;
};



class Manager
{
public:
    Manager(string name) 
    :_name(name)
    {}

    virtual  ~Manager() {}

    void setHeadManager(Manager * superior)
    {
        _superior = superior;
    }

    virtual void handleRequest(Request *) = 0;

protected:
    string _name;
    Manager * _superior;

};


void printSubInfor(Request * req)
{
    cout<<"内容："<<req->getContent()<<endl;
    cout<<"时长： "<<req->getAmount()<<endl;
    cout<<"已批准"<<endl;
}

void printRefInfor(Request * req)
{
    cout<<"内容："<<req->getContent()<<endl;
    cout<<"时长： "<<req->getAmount()<<endl;
    cout<<"已拒绝"<<endl;
}



class CommonManager
:public Manager
{
public:
    CommonManager(string name)
    :Manager(name)
    {}

    void handleRequest(Request * req) override
    {
        if(req->getCategory()=="请假"&&req->getAmount()<=3)
        {
            printSubInfor(req);
            cout<<"submit by CommonManager "<<_name<<endl;
        }else
        {
            _superior->handleRequest(req);
        }
    }

};


class ChiefManager
:public Manager
{
public:
    ChiefManager(string name)
    :Manager(name)
    {}

    void handleRequest(Request * req) override
    {
        if(req->getCategory()=="请假"&&req->getAmount()<=7)
        {
            printSubInfor(req);       
            cout<<"submit by ChiefManager "<<_name<<endl;
        }else
        {
            _superior->handleRequest(req);
        }
    }

};


class GeneralManager
:public Manager
{
public:

    GeneralManager(string name)
    :Manager(name)
    {}

    void handleRequest(Request * req) override
    {
        if(req->getCategory()=="请假"&&req->getAmount()<=15)
        {
            printSubInfor(req);       
            cout<<"submit by GeneralManager "<<_name<<endl;
        }else if(req->getCategory()=="涨工资"&&req->getAmount()<=1500)
        {
            printSubInfor(req);       
            cout<<"submit by GeneralManager "<<_name<<endl;
        }else
        {
            printRefInfor(req);
            cout<<"refused by GeneralManager "<<_name<<endl;
        }
    }

};

