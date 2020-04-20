 
#include "Thread.h"

#include <unistd.h>
#include <stdlib.h>

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
 
class MyThread
: public wd::Thread
{
public:
	~MyThread() {	cout << "~MyThread() " << endl;	}
private:
	void run() override
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
	unique_ptr<wd::Thread> mythread(new MyThread());
	mythread->start();
	mythread->join();

	return 0;
}

void test1()
{
	cout << "main Thread " << pthread_self() << endl;
	MyThread mythread;
	mythread.start();
	mythread.join();

	//MyThread mythread2(mythread);//error 被禁止
}

int main(void)
{
	test1();
	return 0;
}
