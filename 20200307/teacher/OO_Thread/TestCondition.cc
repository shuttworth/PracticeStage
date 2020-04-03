 ///
 /// @file    pthreadTest.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-02 09:45:15
 ///
 
#include "MutexLock.h"
#include "Condition.h"
 
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#include <iostream>
using std::cout;
using std::endl;


//全局变量, 临界资源, 采用互斥访问

class Example
{
public:
	Example()
	: _number(1000)
	, _flag(true)
	, _mutex()
	, _cond(_mutex)
	{}

	void executeTask1();
	void executeTask2();

private:
	int           _number;
	bool          _flag;
	wd::MutexLock _mutex;
	wd::Condition _cond;
};

void Example::executeTask1()
{	//线程1 当flag 为true时，执行减一的操作, 同时把flag设为false, 通知线程2;
	//      当flag 为false时， 阻塞挂起,等待条件成立
	int cnt = 100;
	while(cnt--) {
		_mutex.lock();

		while(_flag == false) {
			_cond.wait();
		}
		--_number;
		printf("sub thread %ld, gNumber = %d\n", (uint64_t)pthread_self(), _number);
		if(_flag == true)
			_flag = false;
		//通知其他线程
		_mutex.unlock();
		_cond.notify();
		sleep(1);
	}
}
 

void Example::executeTask2()
{	//线程2 当flag 为false时，执行减一的操作, 同时把flag设为true, 通知线程1;
	//      当flag 为true时， 阻塞挂起,等待条件成立
	int cnt = 100;
	while(cnt--) {
		_mutex.lock();
		
		while(_flag == true) {
			_cond.wait();
		}
		
		--_number;
		printf("sub thread %ld, gNumber = %d\n", (uint64_t)pthread_self(), _number);
		
		if(_flag == false)
			_flag = true;
		_cond.notify();
		_mutex.unlock();
		sleep(1);
	}
}

int main(void)
{
	printf(">> main thread start running!\n");
	Example example;


	//在linux里面，线程的本质其实还是一个进程 => struct task_struct{...}
	pthread_create(&pthid1, NULL, threadFunc1, NULL);//创建线程 对进程进行复制
	pthread_create(&pthid2, NULL, threadFunc2, NULL);//创建线程

	printf("main thread：%ld, 子线程ids = %ld, %ld\n", 
		(uint64_t)pthread_self(), (uint64_t)pthid1, (uint64_t)pthid2);

	pthread_join(pthid1, NULL);//等待线程pthid执行结束, 阻塞(线程挂起，不再占用CPU)
	pthread_join(pthid2, NULL);
	printf(">> main thread exit!\n");

	//pthread_mutex_destroy(&mutex1);

	pthread_cond_destroy(&cond1);
	return 0;
}
