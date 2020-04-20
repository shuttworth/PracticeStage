#include "Notifier.h"
#include "Observer.h"
#include <list>
#include <string.h>
#include <iostream>
using std::string;
using std::list;

namespace ob{



void BossNotifier::attach(Observer * ob) 
{
    _listNotify.push_back(ob);
}

void BossNotifier::detach(Observer * ob)
{
    for(auto it=_listNotify.begin();it!=_listNotify.end();++it)
    {
        if(*it == ob)
        {
            _listNotify.erase(it);
            break;
        }
    }
}
void BossNotifier::notifyAll()
{
    for(auto it:_listNotify)
    {
        it->update();
    }
}
void BossNotifier::setStatus(string status)
{
    _status = status;    
}
string BossNotifier::getStatus()
{
    return _status;
}





}//end of namespace ob
