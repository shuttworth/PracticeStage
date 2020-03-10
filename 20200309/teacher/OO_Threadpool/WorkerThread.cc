 ///
 /// @file    WorkerThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-09 16:21:07
 ///
 
#include "WorkerThread.h"
#include "Threadpool.h"

namespace wd
{

WorkerThread::WorkerThread(Threadpool & threadpool)
: _threadpool(threadpool)
{}

void WorkerThread::run() 
{
	_threadpool.threadFunc();
}

}//end of namespace wd
