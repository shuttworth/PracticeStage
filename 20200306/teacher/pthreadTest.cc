#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#include <iostream>
using std::cout;
using std::endl;

//线程的执行在进程的空间里面
//
//如果当进程执行结束时，线程也无法执行
//
void * threadFunc(void * )
{
	int cnt = 10;
	while(cnt--) {
		printf("sub thread %u!\n", (unsigned int)pthread_self());
		sleep(1);
	}
	
	return NULL;
}
 
int main(void)
{
	printf(">> main thread start running!\n");
	pthread_t pthid = 0;//可以理解为一个整型数据
	pthread_create(&pthid, NULL, threadFunc, NULL);//创建线程
	printf("main thread：%u, 子线程id = %u\n", (unsigned int)pthread_self(), (unsigned int)pthid);

	int cnt = 10;
	while(cnt--) {
		printf("main thread 1 !\n");
	}
	pthread_join(pthid, NULL);//等待线程pthid执行结束, 阻塞(线程挂起，不再占用CPU)
	//while(1);//使用死循环时，还是有CPU的调度，还会占用CPU的时间片
	printf(">> main thread exit!\n");
	return 0;
}
