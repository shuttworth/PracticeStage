#pragma once

#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
using std::string;


class Country;
class UnitedNations
{
public:
    virtual ~UnitedNations() {}

    virtual void Declare(string ,Country* ) = 0;

};




class Country
{
public:
    Country(string name) 
        :_name(name)
    {}

    virtual ~Country() {}

    virtual void GetMessage(string) = 0;
    virtual void Declare(UnitedNations * ,string ) = 0;

    string getName()
    {
        return _name;
    }
private:
    string _name;
};

class CertainCountry
:public Country
{
public:
    CertainCountry(string name)
        :Country(name)
    {}

    void GetMessage(string msg) override
    {
        cout<<getName()<<" has recevied: "<<msg<<endl;
    }

    void Declare(UnitedNations * uni,string msg) override
    {
        uni->Declare(msg,this);
    }
};

class SecurityCouncil
:public UnitedNations
{
public:

    SecurityCouncil()
    :UnitedNations()
     ,_c1(new CertainCountry("America"))
     ,_c2(new CertainCountry("Iraq"))
    {}


    void Declare(string msg,Country* Country) override
    {
        if(Country->getName()==_c1->getName())
        {
            _c2->GetMessage(msg);
        }
        else if(Country->getName()==_c2->getName())
        {
            _c1->GetMessage(msg);
        }
    }



private:
    CertainCountry * _c1;
    CertainCountry * _c2;

};


