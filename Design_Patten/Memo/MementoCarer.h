#pragma once

#include "RoleStateMemento.h"

class MementoCarer
{
public:
    MementoCarer(RoleStateMemento * rol) 
    :_rol(rol)
    {}

    RoleStateMemento * getMemento()
    {
        return _rol;
    }

private:
    RoleStateMemento * _rol;
};

