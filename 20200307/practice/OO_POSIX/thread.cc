#include "thread.h"
#include <iostream>

namespace wd{

thread::thread()
:_pthid(0)    
,_isRunning(false)
{
    
}

void thread::start()
{
    pthread_create(&_pthid,NULL,threadFunc,this);
    _isRunning=true;
}


void *thread::threadFunc (void *args)
{
    thread * p=static_cast<thread *>(args);
    if(p)
        p->run(); //体现了虚函数特性
    return NULL;
}


void thread::join()
{
    if(_isRunning){
    pthread_join(_pthid,NULL);
    _isRunning = false;
    }
}

thread::~thread()
{
    if(_isRunning)
    {
        pthread_detach(_pthid);
        _isRunning = false;
    }
}


}



