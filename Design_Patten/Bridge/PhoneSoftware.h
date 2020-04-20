#pragma once

#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
using std::string;



class PhoneSoftware
{
public:

    PhoneSoftware() {}
    virtual ~PhoneSoftware() {}
    virtual void runSoftware() = 0;

private:
    
};


class AddressBook
:public PhoneSoftware
{
public:
    void runSoftware() override
    {
        cout<<"This is AddressBook software";
    }

private:

};


class GameSoftware
:public PhoneSoftware
{
public:
    void runSoftware() override
    {
        cout<<"This is GameSoftware software";
    }

private:

};


