 ///
 /// @file    EventfdThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-15 15:34:02
 ///
 
#include "EventfdThread.h"

namespace wd
{

EventfdThread::EventfdThread(EventfdCallback && cb)
: _eventfd(std::move(cb))
, _thread(std::bind(&Eventfd::start, &_eventfd))
{

}

void EventfdThread::start()
{
	_thread.start();
}

void EventfdThread::stop()
{
	_eventfd.stop();
	_thread.join();
}

void EventfdThread::wakeup()
{
	_eventfd.wakeup();
}

}//end of namespace wd
