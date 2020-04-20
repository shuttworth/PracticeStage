#pragma once

#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
using std::string;

namespace bulid{


class Builder
{
public:
    Builder(string nameA,string nameB) 
    :_nameA(nameA)
    ,_nameB(nameB) 
    {}
    
    virtual  ~Builder() {}

    virtual void BuildWashRoom() = 0;
    virtual void BuildDinningRoom() = 0;
    virtual void BuildBedRoom() = 0;

protected:
    string _nameA;
    string _nameB;
};


class HomeBuilderA
:public Builder
{
public:
    HomeBuilderA(string nameA,string nameB)
    :Builder(nameA,nameB)
    {}

    void BuildWashRoom() override
    {
        cout<<"BuildWashRoom() for "<<_nameA<<" and "<<_nameB<<endl;
    }
    
    void BuildDinningRoom() override
    {
        cout<<"BuildDinningRoom() for "<<_nameA<<" and "<<_nameB<<endl;
    }

    void BuildBedRoom() override
    {
        cout<<"BuildBedRoom() for "<<_nameA<<" and "<<_nameB<<endl;
    }

};


class HomeBuilderB
:public Builder
{
public:
    HomeBuilderB(string nameA,string nameB)
    :Builder(nameA,nameB)
    {}

    void BuildWashRoom() override
    {
        cout<<"BuildWashRoom() for "<<_nameA<<" ,but not for"<<_nameB<<endl;
    }
    
    void BuildDinningRoom() override
    {
        cout<<"BuildDinningRoom() for "<<_nameA<<" ,but not for"<<_nameB<<endl;
    }

    void BuildBedRoom() override
    {
        cout<<"BuildBedRoom() for "<<_nameA<<" ,but not for"<<_nameB<<endl;
    }
};










}//end of namespace build
