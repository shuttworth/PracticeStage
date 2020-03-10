 ///
 /// @file    TaskQueue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-03 11:04:54
 ///
 
#include "TaskQueue.h"

#include <iostream>
using std::cout;
using std::endl;
 
namespace wd
{
TaskQueue::TaskQueue(size_t size)
: _queSize(size)
, _que()
, _mutex()
, _notFull(_mutex)
, _notEmpty(_mutex)
{}

bool TaskQueue::full() const
{
	return _que.size() == _queSize;
}

bool TaskQueue::empty() const
{
	return _que.empty();
}

//push方法运行在生产者线程
void TaskQueue::push(int number)
{	
	MutexLockGuard autolock(_mutex);

	while(full()) {
		_notFull.wait();//使用while可以防止_notFull被异常唤醒
	}

	_que.push(number);//生产者线程放数据
	_notEmpty.notify();//通知消费者线程取数据
}

//pop方法运行在消费者线程
int TaskQueue::pop()
{
	MutexLockGuard autolock(_mutex);
    //MutexLockGuard(_mutex) 这样的写法不可以，因为临时对象的生命周期只存在于当前语句，下一句就解锁了
    while(empty()) {
		_notEmpty.wait();
	}

	int ret = _que.front();
	_que.pop();
	_notFull.notify();//通知生产者线程放数据

	return ret;
}

}// end of namespace wd
