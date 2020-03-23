#pragma once

#include "Timer.h"
#include "Thread.h"


namespace wd {

class TimerThread
{
    using TimerCallback = std::function<void()>;
public:
    TimerThread(TimerCallback && cb,int initialTime,int periodicTime);
    void start();
    void stop();

private:
    Timer _timer;
    Thread _thread;

};


}// end of namespace wd 

