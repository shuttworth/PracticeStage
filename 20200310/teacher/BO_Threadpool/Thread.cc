 ///
 /// @file    Thread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-02 14:43:26
 ///
 
#include "Thread.h"
namespace wd
{

Thread::Thread(ThreadCallback && callback)
: _callback(std::move(callback))
, _pthid(0)
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
		p->_callback();//执行回调函数

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
	cout << "~Thread()" << endl;
}

}//end of namespace wd
