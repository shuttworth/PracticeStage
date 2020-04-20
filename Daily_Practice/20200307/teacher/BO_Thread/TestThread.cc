 ///
 /// @file    TestThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-02 14:59:05
 ///
 
#include "Thread.h"

#include <unistd.h>
#include <stdlib.h>

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
 
class Task
{
public:
	void process()
	{
		int cnt = 10;
		::srand(::clock());
		while(cnt--) {
			int number = ::rand() % 100;
			cout << "sub Thread " << pthread_self() 
				 << ": getNumber = " << number << endl;
			::sleep(1);
		}
	}
};


int test0(void)
{
	cout << "main Thread " << pthread_self() << endl;
	
	Task task;
	unique_ptr<wd::Thread> mythread(new wd::Thread(
		std::bind(&Task::process, &task)
	));
	mythread->start();
	mythread->join();

	return 0;
}

void process()
{
	int cnt = 10;
	::srand(::clock());
	while(cnt--) {
		int number = ::rand() % 100;
		cout << "sub Thread " << pthread_self() 
			 << ": getNumber = " << number << endl;
		::sleep(1);
	}
}

void test1()
{
	cout << "main Thread " << pthread_self() << endl;
	wd::Thread mythread(process);
	mythread.start();
	mythread.join();

	//wd::Thread mythread2(mythread);//error 被禁止
}

int main(void)
{
	//test0();
	test1();
	return 0;
}
