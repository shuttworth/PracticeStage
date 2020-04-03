#pragma once

#include "noncopy.h"
#include <pthread.h>

namespace  wd{
class thread
{
public:
    thread();
    virtual ~thread();
    
    void start();
    void join();
    
    virtual void run() = 0; 
    
    bool isRunning() const
    {
        return _isRunning;
    }

private:
    static void * threadFunc(void * );

    pthread_t _pthid;
    bool _isRunning;
};
}//end of namespace wd

