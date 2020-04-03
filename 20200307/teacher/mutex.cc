 ///
 /// @file    pthreadTest.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-02 09:45:15
 ///
 
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#include <iostream>
using std::cout;
using std::endl;


//全局变量, 临界资源, 采用互斥访问
int gNumber = 1000;

pthread_mutex_t mutex1;
//线程的执行在进程的空间里面
//
//如果当进程执行结束时，线程也无法执行
//
//线程有各自的栈空间
void * threadFunc1(void * )
{
	int cnt = 100;
	while(cnt--) {
		pthread_mutex_lock(&mutex1);
		--gNumber;
		printf("sub thread %ld, gNumber = %d\n", (uint64_t)pthread_self(), gNumber);
		pthread_mutex_unlock(&mutex1);
		sleep(1);
	}
	return NULL;
}
 

void * threadFunc2(void * )
{
	int cnt = 100;
	while(cnt--) {
		pthread_mutex_lock(&mutex1);
		//pthread_mutex_lock(&mutex1);
		--gNumber;
		printf("sub thread %ld, gNumber = %d\n", (uint64_t)pthread_self(), gNumber);
		pthread_mutex_unlock(&mutex1);
		sleep(1);
	}
	return NULL;
}
int main(void)
{
	//int cnt = 10;
		
	pthread_mutex_init(&mutex1, NULL);//动态初始化互斥锁

	printf(">> main thread start running!\n");
	pthread_t pthid1 = 0, pthid2 = 0;//定义线程的id
	pthread_t pthid3 = 0, pthid4 = 0;//定义线程的id

	//在linux里面，线程的本质其实还是一个进程 => struct task_struct{...}
	pthread_create(&pthid1, NULL, threadFunc1, NULL);//创建线程 对进程进行复制
	pthread_create(&pthid2, NULL, threadFunc1, NULL);//创建线程
	pthread_create(&pthid3, NULL, threadFunc2, NULL);//创建线程
	pthread_create(&pthid4, NULL, threadFunc2, NULL);//创建线程
	printf("main thread：%ld, 子线程ids = %ld, %ld\n", 
		(uint64_t)pthread_self(), (uint64_t)pthid1, (uint64_t)pthid2);

	pthread_join(pthid1, NULL);//等待线程pthid执行结束, 阻塞(线程挂起，不再占用CPU)
	pthread_join(pthid2, NULL);

	pthread_mutex_destroy(&mutex1);
	printf(">> main thread exit!\n");

	return 0;
}
