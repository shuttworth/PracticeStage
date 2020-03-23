 ///
 /// @file    Thread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-02 14:36:45
 ///
#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__
#include <iostream>
#include <functional>
using std::cout;
using std::endl;

#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{

class Thread
: Noncopyable
{// 具有对象语义的类  =》  不能被复制
public:
	using ThreadCallback = std::function<void()>;
	//typedef std::function<void ()> ThreadCallback;这么写也是可以的
    Thread(ThreadCallback && callback);
	
	~Thread();

	void start();//开启子线程
	void join();//回收子线程

	bool isRunning() const {	return _isRunning;	}
	pthread_t getThreadid() const {	return _pthid;	}

private:

	//static 成员函数不带this指针,回调函数设置成static是一贯的做法，消去this指针
	static void * threadFunc(void *);

private:
	ThreadCallback _callback;//回调函数，表示线程即将要执行的任务
	pthread_t _pthid;
	bool _isRunning;
};

}//end of namespace wd
 

#endif
