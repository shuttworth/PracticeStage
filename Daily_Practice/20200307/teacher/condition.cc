#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#include <iostream>
using std::cout;
using std::endl;


//全局变量, 临界资源, 采用互斥访问
int gNumber = 1000;

pthread_mutex_t mutex1;
pthread_cond_t cond1;
bool flag = true;

void * threadFunc1(void * )
{	//线程1 当flag 为true时，执行减一的操作, 同时把flag设为false, 通知线程2;
	//      当flag 为false时， 阻塞挂起,等待条件成立
	int cnt = 100;
	while(cnt--) {
		pthread_mutex_lock(&mutex1);//使用条件变量前，必须进行加锁

		while(flag == false) {
			pthread_cond_wait(&cond1, &mutex1);//阻塞, 在线程阻塞的同时解锁，否则就会死锁;
			//如果其他线程发送signal之后，当前wait被激活(唤醒)，激活之后首先要进行加锁
		}

		--gNumber;
		printf("sub thread %ld, gNumber = %d\n", (uint64_t)pthread_self(), gNumber);
		if(flag == true)
			flag = false;
		//通知其他线程
		pthread_mutex_unlock(&mutex1);
		pthread_cond_signal(&cond1);
		sleep(1);
	}
	return NULL;
}
 

void * threadFunc2(void * )
{	//线程2 当flag 为false时，执行减一的操作, 同时把flag设为true, 通知线程1;
	//      当flag 为true时， 阻塞挂起,等待条件成立
	int cnt = 100;
	while(cnt--) {
		pthread_mutex_lock(&mutex1);
		
		while(flag == true) {
			pthread_cond_wait(&cond1, &mutex1);
		}
		
		--gNumber;
		printf("sub thread %ld, gNumber = %d\n", (uint64_t)pthread_self(), gNumber);
		
		if(flag == false)
			flag = true;
		pthread_cond_signal(&cond1);//给另外一个线程发信号，唤醒wait方法
		pthread_mutex_unlock(&mutex1);
		sleep(1);
	}
	return NULL;
}
int main(void)
{
	//int cnt = 10;
		
	pthread_mutex_init(&mutex1, NULL);//初始化互斥锁
	pthread_cond_init(&cond1, NULL);//初始化条件变量

	printf(">> main thread start running!\n");
	pthread_t pthid1 = 0, pthid2 = 0;//定义线程的id

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
