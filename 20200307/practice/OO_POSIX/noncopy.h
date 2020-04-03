#pragma once

namespace  wd
{

class noncopy
{
public:
    noncopy() {}
    ~noncopy() {}

private:
    noncopy(const noncopy & rhs)= delete ;
    noncopy & operator =(const noncopy & )= delete ;
};

}//end of namespace wd
