 ///
 /// @file    TestThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-02 14:59:05
 ///
 
#include "Thread.h"
#include "Producer.h"
#include "Consumer.h"

#include <unistd.h>
#include <stdlib.h>

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
using namespace wd;
 
void test0()
{
	cout << "main Thread " << pthread_self() << endl;
	wd::TaskQueue taskque(10);
	unique_ptr<wd::Thread> producer(new wd::Thread(//Thread内部传的是一个函数对象
		std::bind(&Producer::produce, Producer(), std::ref(taskque)) //靠bind来给produce传数据成员
	));//C++11的设计者认为bind默认应该采用拷贝，如果使用者有需求，加上std::ref()即可。同理std::thread也是这样
	unique_ptr<wd::Thread> consumer(new wd::Thread(
		std::bind(&Consumer::consume, Consumer(), std::ref(taskque))
	));
	
	producer->start();
	consumer->start();
	producer->join();
	consumer->join();
}

int main(void)
{
	test0();
	return 0;
}
