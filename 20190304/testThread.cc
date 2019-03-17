#include "MutexLock.h"
#include "Condition.h"
#include <iostream>

using std::cout;
using std::endl;
using namespace wd;

int gNumber=0;
MutexLock mutex;//都在wd空间里面
Condition cond(mutex);
bool flag=true;

void * func1(void* )//由pthread_create的man看出来,func1作为第三个参数这里必须为void*型，传void*参数
{
    int cnt=10;
    while(cnt--)
    {
        MutexLockGuard autolock(mutex);
        if(flag==false)//false 的时候才阻塞，true的时候执行就++操作
        {
            cond.wait();
        }
        ++gNumber;
        cout<<"subThread1: "<<pthread_self()//获取线程id的方法
            <<" gNumber ="<<gNumber<<endl;
        flag=false;
        cond.notify();
    }
    return NULL;
}

void * func2(void* )
{
    int cnt=10;
    while(cnt--)
    {
        MutexLockGuard autolock(mutex);
        if(flag==true)
        {
            cond.wait();
        }
        ++gNumber;
        cout<<"subThread2: "<<pthread_self()
            <<" gNumber ="<<gNumber<<endl;
        flag=true;
        cond.notify();
    }
    return NULL;
}



int main(void)
{
    pthread_t pth1,pth2;
    pthread_create(&pth1,NULL,func1,NULL);
    pthread_create(&pth2,NULL,func2,NULL);
    
    pthread_join(pth1,NULL);
    pthread_join(pth2,NULL);

    return 0;
}

