#pragma once

#include "PhoneSoftware.h"
#include <vector>
using std::vector;

class Brand
{
public:
    Brand(string name) 
    :_name(name)
    {}

    virtual ~Brand() {}

    virtual void runSoftware() = 0;
    
    void addSoftWare(PhoneSoftware * psw) 
    {
        _psoftware.push_back(psw);
    }

protected:
    string _name;
    vector<PhoneSoftware *> _psoftware; //来改成一个队列，挨个执行
};


class PhoneBrand1
:public Brand
{
public:
    PhoneBrand1(string name)
    :Brand(name)
    {}

    void runSoftware() override
    {
        for(auto & it :_psoftware)
        {
            it->runSoftware();
            cout<<" of "<<_name<<endl;
        }
    }
};






