#pragma once
#include "builder.h"

namespace bulid{

class Director
{
public:
    Director(Builder * director) 
    :_director(director)
    {}
    
    void createBuilder() 
    {
        _director->BuildWashRoom();
        _director->BuildDinningRoom();
        _director->BuildBedRoom();
    }

private:
    Builder * _director;
};







}//end of namespace bulid
