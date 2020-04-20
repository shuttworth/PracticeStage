 ///
 /// @file    Thread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-02 14:43:26
 ///
 
#include "Thread.h"
namespace wd
{

Thread::Thread()
: _pthid(0)
, _isRunning(false)
{
	
}

void Thread::start()
{
	pthread_create(&_pthid, NULL, threadFunc, this);
	_isRunning = true;
}

void * Thread::threadFunc(void * arg)
{
	Thread * p = static_cast<Thread *>(arg);
	if(p)
		p->run();//表现虚函数机制

	return NULL;
}

void Thread::join()
{
	if(_isRunning) {
		pthread_join(_pthid, NULL);
		_isRunning = false;
	}
}

Thread::~Thread()
{
	if(_isRunning) {
		pthread_detach(_pthid);	
		_isRunning = false;
	}
}

}//end of namespace wd
