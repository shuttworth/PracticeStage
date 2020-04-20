#include "TimerThread.h"


namespace wd{

TimerThread::TimerThread(TimerCallback && cb,int initialTime,int periodicTime)
:_timer(std::move(cb),initialTime,periodicTime)
,_thread(std::bind(&Timer::start,&_timer))    
{

}



void TimerThread::start()
{
    _thread.start();
}

void TimerThread::stop()
{
    _timer.stop();
    _thread.join();
}



}



