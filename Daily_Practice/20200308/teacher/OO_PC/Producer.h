 ///
 /// @file    Producer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-03 11:18:14
 ///

#ifndef __WD_PRODUCER_H__
#define __WD_PRODUCER_H__

#include "Thread.h"
#include "TaskQueue.h"

#include <stdlib.h>

namespace wd
{

class Producer
: public Thread
{
public:
	Producer(TaskQueue & taskque)
	: _taskque(taskque)
	{}

private:
	void run() override
	{
		::srand(::clock());
		int cnt = 20;
		while(cnt--) {
			int number = ::rand() % 100;
			_taskque.push(number);
			cout << ">> producer " << pthread_self() << ":"
				 << " produce a number = " << number << endl;
		}
	}

private:
	TaskQueue & _taskque;
};

}//end of namespace wd


#endif
