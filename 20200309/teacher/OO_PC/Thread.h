 ///
 /// @file    Thread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-02 14:36:45
 ///
#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__
#include <iostream>
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
	Thread();
	
	virtual
	~Thread();

	void start();//开启子线程
	void join();//回收子线程

	bool isRunning() const {	return _isRunning;	}

private:
	virtual void run()=0;//这是线程要执行的任务

	//static 成员函数不带this指针
	static void * threadFunc(void *);

private:
	pthread_t _pthid;
	bool _isRunning;
};

}//end of namespace wd
 

#endif
