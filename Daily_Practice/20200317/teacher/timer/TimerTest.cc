 ///
 /// @file    TimerTest.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-15 12:00:36
 ///
 
#include "TimerThread.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

struct Example
{
	void process() {
		::srand(::clock());
		int number = ::rand() % 100;
		cout << " number = " << number << endl;
	}
};
 
int main(void)
{
	cout << ">>> main thread " << pthread_self() << endl;
	wd::TimerThread timer(std::bind(&Example::process, Example()), 3, 5);  //bind把方法传过去
	timer.start();//应该让其在子线程中去执行
	cout << ">>> main thread: sub thread start running a timer..." << endl;
	cout << ">>> main thread sleep..." << endl;
	sleep(15);
	cout << ">>> main thread wakeup..." << endl;
	cout << ">>> main thread stop timer..." << endl;
	timer.stop();//在主线程中执行
	return 0;
}
