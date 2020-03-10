 ///
 /// @file    Consumer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-03 11:22:52
 ///
#ifndef __WD_CONSUMER_H__
#define __WD_CONSUMER_H__

#include "TaskQueue.h"

#include <unistd.h>

#include <iostream>
using namespace std;

namespace wd
{
class Consumer
{
public:
	void consume(TaskQueue & taskque)
	{
		int cnt = 20;
		while(cnt--) {
			int number = taskque.pop();
			cout << ">> consumer " << pthread_self()
				 << " : consume a number = " << number << endl;
			::sleep(1);
		}
	}
};

}//end of namespace wd

#endif
