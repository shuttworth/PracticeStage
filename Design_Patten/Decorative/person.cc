#include "person.h"

namespace dec
{

person::person(string name)
:_name(name)
{}


void  person::show(){
    cout<<"装饰的"<<_name<<endl;
}




}//end of namespace dec
