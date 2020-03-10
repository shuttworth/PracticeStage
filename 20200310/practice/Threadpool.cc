#include "Threadpool.h"
#include "WorkerThread.h"

#include <unistd.h>


namespace wd{

Threadpool::Threadpool(size_t threadNum,size_t queSize)
:_threadNum(threadNum)
,_threads()    
,_queSize(queSize)
,_queTask(_queSize)
,_isExit(false)    
{
    _threads.reserve(_threadNum);
}

Threadpool::~Threadpool()
{
    if(!_isExit)
    {
        stop();
    }
}

void Threadpool::start()
{
    for(size_t idx=0;idx!=_threadNum;++idx)
    {
        unique_ptr<Thread> up(new WorkerThread(*this));
        _threads.push_back(std::move(up));
    }

    for(auto & elm:_threads)
    {
        elm->start();
    }
}

void Threadpool::addTask(TaskType ptask)
{
    _queTask.push(ptask);
}

TaskType Threadpool::getTask()
{
    return _queTask.pop();
}


void Threadpool::ThreadFunc()
{
    while(!_isExit){
        TaskType ptask = getTask();
        if(ptask)
            ptask->process();
    }
}

void Threadpool::stop()
{
    cout << " >>> main thread Threadpool::stop() entering"<<endl;
    if(!_isExit){
        while(!_queTask.empty())
        {
            ::usleep(100);
        }
        _isExit = true;
        _queTask.wakeup();

        for(auto & elm:_threads)
        {
            elm->join();
        }
    }
    cout << " >>> main thread Threadpool::stop()  exit "<<endl;
}


}//end of namespace wd
