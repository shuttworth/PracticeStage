 ///
 /// @file    TimerThread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-15 15:31:19
 ///
 
#ifndef __WD_TIMERTHREAD_H__
#define __WD_TIMERTHREAD_H__

#include "Thread.h"
#include "Timer.h"

namespace wd
{

class TimerThread
{
	using TimerCallback = std::function<void()>;
public:
	TimerThread(TimerCallback && cb, int initialTime, int periodicTime);

	void start();
	void stop();

private:
	Timer _timer;
	Thread _thread;
};

}//end of namespace wd


#endif
