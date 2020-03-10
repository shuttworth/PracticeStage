#pragma once

#include "Task.h"
#include "TaskQueue.h"
#include <vector>
#include <memory>

using namespace std;

namespace wd{

class Thread;

class Threadpool
{
    friend class WorkerThread;


public:
    Threadpool(size_t threadNum,size_t queSize);
    ~Threadpool();

    void  addTask(TaskType);
    void start();
    void stop();

private:
    void ThreadFunc();
    TaskType getTask();

private:
    size_t _threadNum;
    vector<unique_ptr<Thread>> _threads;
    size_t _queSize;
    TaskQueue _queTask;
    bool _isExit;
};


}//end of namespace wd
