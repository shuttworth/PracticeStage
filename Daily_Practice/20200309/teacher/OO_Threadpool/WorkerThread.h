 ///
 /// @file    WorkerThread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-09 16:17:45
 ///
 
#ifndef __WD_WORKERTHREAD_H__
#define __WD_WORKERTHREAD_H__
#include "Thread.h"

namespace wd
{
class Threadpool;

class WorkerThread
: public Thread
{
public:
	WorkerThread(Threadpool & threadpool);

private:
	void run() override;
private:
	Threadpool & _threadpool;
};

}//end of namespace wd
#endif
