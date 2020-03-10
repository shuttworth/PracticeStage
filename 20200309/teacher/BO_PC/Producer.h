 ///
 /// @file    Producer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-03 11:18:14
 ///

#ifndef __WD_PRODUCER_H__
#define __WD_PRODUCER_H__

#include "TaskQueue.h"

#include <stdlib.h>

#include <iostream>
using namespace std;


namespace wd
{

class Producer
{
public:
	void produce(TaskQueue & taskque) 
	{
		::srand(::clock());
		int cnt = 20;
		while(cnt--) {
			int number = ::rand() % 100;
			taskque.push(number);
			cout << ">> producer " << pthread_self() << ":"
				 << " produce a number = " << number << endl;
		}
	}
};

}//end of namespace wd


#endif
