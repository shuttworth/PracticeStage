 ///
 /// @file    TimerTest.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-15 12:00:36
 ///
 
#include "EventfdThread.h"

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
	wd::EventfdThread eventfd(std::bind(&Example::process, Example()));
	eventfd.start();//应该让其在子线程中去执行
	cout << ">>> main thread: notify sub thread to run a task once a second..." << endl;
	int cnt = 10;
	while(cnt--) {
		eventfd.wakeup();
		sleep(1);
	}
	cout << ">>> main thread stop ..." << endl;
	eventfd.stop();//在主线程中执行
	return 0;
}
