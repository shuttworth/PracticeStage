#pragma once
#include <iostream>
using std::cout;
using std::endl;

namespace Product{

class LeiFeng
{
public:
    virtual void sweep() ;
    virtual void buyRice() ;
    virtual void wash() ;
    virtual ~LeiFeng(){}

};


class Undergraduate
:public LeiFeng
{
    void sweep() override;
    void buyRice() override;
    void wash() override;
};


class Volunteers
:public LeiFeng
{
    void sweep() override;
    void buyRice() override;
    void wash() override;
};







}//end of namespace Product
