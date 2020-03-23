 ///
 /// @file    TimerThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-15 15:34:02
 ///
 
#include "TimerThread.h"

namespace wd
{

TimerThread::TimerThread(TimerCallback && cb, int initialTime, int periodicTime)
: _timer(std::move(cb), initialTime, periodicTime)
, _thread(std::bind(&Timer::start, &_timer))
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


}//end of namespace wd
