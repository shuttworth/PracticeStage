 ///
 /// @file    Consumer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-03 11:22:52
 ///
#ifndef __WD_CONSUMER_H__
#define __WD_CONSUMER_H__

#include "Thread.h" 
#include "TaskQueue.h"

namespace wd
{
class Consumer
: public Thread
{
public:
	Consumer(TaskQueue & taskque)
	: _taskque(taskque)
	{}

private:
	void run() override
	{
		int cnt = 20;
		while(cnt--) {
			int number = _taskque.pop();
			cout << ">> consumer " << pthread_self()
				 << " : consume a number = " << number << endl;
		}
	}

private:
	TaskQueue & _taskque;
};

}//end of namespace wd

#endif
