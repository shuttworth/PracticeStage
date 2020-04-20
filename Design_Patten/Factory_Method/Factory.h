#pragma once
#include "Product.h"


namespace Product{

class iFactory
{
public:
    virtual LeiFeng * createLeiFeng()
    {
        return new LeiFeng();
    }
};

class UndergraduateFactory
:public iFactory
{
public:
    Undergraduate * createLeiFeng() override
    {
        return  new Undergraduate(); 
    }
};

class VolunteersFactory
:public iFactory
{
public:
    LeiFeng * createLeiFeng() override
    {
        return  new Volunteers(); 
    }
};

}//end of namespace Product
