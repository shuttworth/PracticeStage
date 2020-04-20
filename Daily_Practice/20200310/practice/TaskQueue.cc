#include "TaskQueue.h"

#include <iostream>

using std::cout;
using std::endl;

namespace wd{

TaskQueue::TaskQueue(size_t size)
:_queSize(size)
,_que()
,_mutex()
,_notfull(_mutex)
,_notempty(_mutex)
,_used(true)
{}

bool TaskQueue::full() const
{
    return _que.size()==_queSize; 
}

bool TaskQueue::empty() const
{
    return _que.empty(); 
}

void TaskQueue::push(const TaskType & t)
{
    MutexLockGuard autolock(_mutex);
    while(full())
    {
        _notfull.wait();
    }

    _que.push(t);
    _notempty.notify();
}

TaskType TaskQueue::pop()
{
    MutexLockGuard autolock(_mutex);
    while(_used && empty())
    {
        _notempty.wait();
    }
    
    if(_used){
    TaskType ret = _que.front();
    _que.pop();
    _notfull.notify();
    return ret;
    }
    else
    return NULL;
}

void TaskQueue::wakeup()
{
    if(_used) _used=false;
    _notempty.notifyall();
}



}//end of namespace wd



