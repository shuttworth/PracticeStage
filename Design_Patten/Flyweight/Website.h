#pragma once
#include <iostream>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
using std::cout;
using std::endl;
using std::string;
using std::unordered_set;
using std::unordered_map;

class User
{
public:
    User(string name)
    :_name(name)
    {}

    string getName()
    {
        return _name;
    }

private:
    string _name;

};


class Website
{
public:
    Website(string name)
    :_webName(name)
    {}
    
    virtual  ~Website() {}

    virtual void Server(User * ) = 0;

    string getWebName()
    {
        return _webName;
    }

private:
    string _webName;
};


class ConcreteWebsite
:public Website
{
public:

    ConcreteWebsite(string name)
    :Website(name)
    {}

    void Server(User * user) override
    {
        cout<<getWebName()<<" is serving ; user is "<<user->getName()<<endl;      
    }
    
};

class WebFacory
{
public:
    //C++20 contains
    Website * createWeb(string webname) 
    {
        /* if(_webList.contains(webname)) */
        auto it = _webList.find(webname);
        if(it==_webList.end())
        {
            Website * newWebsite = new ConcreteWebsite(webname);
            _webList.insert(std::make_pair(webname,newWebsite));
            cout<<"create successfully! "<<endl;
        }
            return _webList[webname];
    }


private:
    unordered_map<string,Website *>_webList;



};

