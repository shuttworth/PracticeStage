#pragma once

#include <iostream>
#include <string.h>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::endl;


class Company
{

public:
    Company(string conName) 
    :_conName(conName)
    {}
    
    virtual    ~Company() {}

    virtual void addCom(Company *) = 0;
    virtual void delCom(Company *) = 0;
    virtual void Display(int ) = 0;
    virtual void ShowDuty() = 0;

protected:
    string _conName;
};


class ConcreteCompany
:public Company
{
public:
    ConcreteCompany(string name)
    :Company(name)
    {}
    
    void addCom(Company * newCom) override
    {
        _vec.push_back(newCom);
    }


    void delCom(Company * com) override
    {
        for(auto it = _vec.begin();it!=_vec.end();++it)
        {
            if(*it==com)
            {
                _vec.erase(it);
                break;
            }else{
                cout<<"delcom failed"<<endl;
            }
        }
    }

    void ShowDuty() override
    {
        for(auto & it:_vec)
        {
            it->ShowDuty();
        }
    }

    void Display(int depth) override
    {
        cout<<*new string(depth,'-')<<_conName<<endl;
        for(auto &it:_vec)
        {
            it->Display(depth+1);
        }
    }


private:
    vector<Company *> _vec;

};


class HRdepartment
:public Company
{
public:
    HRdepartment(string name)
    :Company(name)
    {}

    void addCom(Company *) override
    {};

    void delCom(Company *) override
    {}

    void Display(int depth) override
    {
        cout<<*new string(depth,'-')<<_conName<<endl;
    }
    
    void ShowDuty() override
    {
        cout<<_conName<<" HRdepartment is running"<<endl;
    }

};


class ProductDepartment
:public Company
{
public:
    ProductDepartment(string name)
    :Company(name)
    {}

    void addCom(Company *) override
    {};

    void delCom(Company *) override
    {}

    void Display(int depth) override
    {
        cout<<*new string(depth,'-')<<_conName<<endl;
    }
    
    void ShowDuty() override
    {
        cout<<_conName<<" ProductDepartment is running"<<endl;
    }

};

class MarketDepartment
:public Company
{
public:
    MarketDepartment(string name)
    :Company(name)
    {}

    void addCom(Company *) override
    {};

    void delCom(Company *) override
    {}

    void Display(int depth) override
    {
        cout<<*new string(depth,'-')<<_conName<<endl;
    }
    
    void ShowDuty() override
    {
        cout<<_conName<<" MarketDepartment is running"<<endl;
    }

};

