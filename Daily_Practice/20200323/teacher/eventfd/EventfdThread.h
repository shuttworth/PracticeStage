 ///
 /// @file    EventfdThread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-15 15:31:19
 ///
 
#ifndef __WD_TIMERTHREAD_H__
#define __WD_TIMERTHREAD_H__

#include "Thread.h"
#include "Eventfd.h"

namespace wd
{

class EventfdThread
{
	using EventfdCallback = std::function<void()>;
public:
	EventfdThread(EventfdCallback && cb);

	void start();
	void stop();
	void wakeup();

private:
	Eventfd _eventfd;
	Thread _thread;
};

}//end of namespace wd


#endif
