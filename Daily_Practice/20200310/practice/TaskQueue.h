#pragma once

#include "MutexLock.h"
#include "Condition.h"

#include <queue>

namespace wd{

class Task;
using TaskType = Task*;


class TaskQueue
{
public:
    TaskQueue(size_t size);

    bool full() const;
    bool empty() const;

    void push(const TaskType & t);
    TaskType pop();

    void wakeup();

private:
    size_t _queSize;
    std::queue<TaskType> _que;
    MutexLock _mutex;
    Condition _notfull;
    Condition _notempty;
    bool _used;
};




}//end of namespace wd
