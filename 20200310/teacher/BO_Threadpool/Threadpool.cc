 ///
 /// @file    Threadpool.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-09 16:12:41
 ///
 
#include "Threadpool.h"
#include "Thread.h"

#include <unistd.h>

namespace wd
{

Threadpool::Threadpool(size_t threadNum, size_t queSize)
: _threadNum(threadNum)
, _threads()
, _queSize(queSize)
, _taskque(_queSize)
, _isExit(false)
{
	_threads.reserve(threadNum);
}

Threadpool::~Threadpool()
{
	if(!_isExit) 
		stop();
}

//启动线程池
void Threadpool::start()
{
	for(size_t idx = 0; idx != _threadNum; ++idx) {
		unique_ptr<Thread> up(new Thread(
			std::bind(&Threadpool::threadFunc, this)			
		));
		_threads.push_back(std::move(up));
	}

	for(auto & threadPtr : _threads)
		threadPtr->start();
}

//添加任务
void Threadpool::addTask(Task && task)
{
	_taskque.push(std::move(task));
}

//获取任务
Task Threadpool::getTask()
{
	return _taskque.pop();
}

//每一个子线程要执行的任务: 不断的去任务队列之中获取任务并执行
void Threadpool::threadFunc()
{
	while(!_isExit) {
		Task task = getTask();
		if(task)
			task();
	}
}

//停止线程池
void Threadpool::stop()
{
	if(!_isExit) {
		while(!_taskque.empty()) {
			::usleep(100);
		}
		_isExit = true;
		_taskque.wakeup();
		
		for(auto & threadPtr : _threads) {
			threadPtr->join();
		}
	}
}

}//end of namespace wd
