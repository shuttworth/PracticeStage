 ///
 /// @file    Threadpool.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-09 16:12:41
 ///
 
#include "Threadpool.h"
#include "WorkerThread.h"

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
    //先往线程池里填满线程，再挨个启动
	for(size_t idx = 0; idx != _threadNum; ++idx) {
		unique_ptr<Thread> up(new WorkerThread(*this));//WorkerThread作用是创建一个线程,参数是*WorkThreadpool
		_threads.push_back(std::move(up));//每次转移右值引用后，再重新开辟
	}

	for(auto & threadPtr : _threads)
		threadPtr->start();//是Thread里面的start,用来开启线程
}

//添加任务,线程任务在队列里
void Threadpool::addTask(Task * ptask)
{
	_taskque.push(ptask);
}

//获取任务
Task * Threadpool::getTask()
{
	return _taskque.pop();
}

//每一个子线程要执行的任务: 不断的去任务队列之中获取任务并执行
void Threadpool::threadFunc()
{
	while(!_isExit) {
		Task * ptask = getTask();//获取任务
		if(ptask)
			ptask->process();//执行任务  任务执行的时间长短 Task里的接口，MyTask实现的
	}
}

//停止线程池
void Threadpool::stop()
{
	cout << " >>> main thread Threadpool::stop() entering" << endl;
	if(!_isExit) {
		//在退出线程池之前，要确保所有的任务都被执行完毕了
		while(!_taskque.empty()) {
			//::sleep(1);	//bug: 如果在休眠的过程中，所有的子线程已经将任务执行完毕，并且阻塞在getTask方法之上
						//即使将_isExit设置为true, 子线程也不会正常退出的
			::usleep(100);//为了防止CPU空转, 让线程休眠100微秒
		}
		//退出while循环，表示所有的任务都被子线程取走了(任务是否执行完毕是不确定的)
		_isExit = true;
		//唤醒所有的子线程
		_taskque.wakeup();
		
		//回收每一个子线程的资源
		for(auto & threadPtr : _threads) {
			threadPtr->join();//等待每一个子线程执行完毕
		}
	}
	cout << " >>> main thread Threadpool::stop()  exit " << endl;
}

}//end of namespace wd
