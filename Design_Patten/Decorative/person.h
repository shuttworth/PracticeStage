#pragma once

#include <iostream>
#include <string.h>
using std::string;
using std::cout;
using std::endl;


namespace dec{


class person
{
public:
    person() {}
    person(string );

    virtual void show();
    virtual ~person(){}
private:
    string _name;
};


}//end of namespace dec
