 ///
 /// @file    TaskQueue.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-03 11:01:32
 ///
 
#ifndef _WD_TASKQUEUE_H__
#define _WD_TASKQUEUE_H__

#include "MutexLock.h"
#include "Condition.h"

#include <queue>


namespace wd
{

class Task;
using TaskType = Task*;	

class TaskQueue
{
public:
	TaskQueue(size_t size);

	bool full() const;
	bool empty() const;
	void push(const TaskType & t);
	TaskType pop();

	void wakeup();//激活所有的等待_notEmpty条件变量的线程

private:
	size_t _queSize;
	std::queue<TaskType> _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
	bool _used;
};

}//end of namespace wd


#endif
