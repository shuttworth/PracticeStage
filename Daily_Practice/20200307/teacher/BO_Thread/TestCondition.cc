 ///
 /// @file    pthreadTest.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-02 09:45:15
 ///
 
#include "Thread.h"
#include "MutexLock.h"
#include "Condition.h"
 
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

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
        wd::MutexLock::MutexLockGuard  autoLock(_mutex);
        //	_mutex.lock();

		while(_flag == false) {
			_cond.wait();
		}
		--_number;
		printf("sub thread %ld, gNumber = %d\n", (uint64_t)pthread_self(), _number);
		if(_flag == true)
			_flag = false;
		//通知其他线程
	//	_mutex.unlock();
		_cond.notify();
	}
}
 

void Example::executeTask2()
{	//线程2 当flag 为false时，执行减一的操作, 同时把flag设为true, 通知线程1;
	//      当flag 为true时， 阻塞挂起,等待条件成立
	int cnt = 100;
	while(cnt--) {
	    wd::MutexLock::MutexLockGuard autoLock(_mutex);
        //	_mutex.lock();
		
		while(_flag == true) {
			_cond.wait();
		}
		
		--_number;
		printf("sub thread %ld, gNumber = %d\n", (uint64_t)pthread_self(), _number);
		
		if(_flag == false)
			_flag = true;
		_cond.notify();
	//	_mutex.unlock();
	}
}

int test0(void)
{
	printf(">> main thread start running!\n");
	Example example;

	unique_ptr<wd::Thread> thread1(new wd::Thread(
		std::bind(&Example::executeTask1, &example)
	));

	unique_ptr<wd::Thread> thread2(new wd::Thread(
		std::bind(&Example::executeTask2, &example)
	));

	thread1->start();
	thread2->start();

	printf("main thread：%ld, 子线程ids = %ld, %ld\n", 
		(uint64_t)pthread_self(), 
		(uint64_t)thread1->getThreadid(), 
		(uint64_t)thread2->getThreadid());

	thread1->join();
	thread2->join();

	printf(">> main thread exit!\n");
	return 0;
}

int main(void)
{
	test0();
	return 0;
}
