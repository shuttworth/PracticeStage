#include "MutexLock.h"
#include "Condition.h"
#include <iostream>

using std::cout;
using std::endl;
using namespace wd;

int gNumber=0;
MutexLock mutex;
Condition cond(mutex);
bool flag=true;

void * func1(void *)
{
    int cnt=10;
    while(cnt--)
    {
        MutexLockGuard autolock(mutex);
        if(flag==false)
        {
            cond.wait();
        }
        ++gNumber;//进入的时候是true的
        cout<<"subThread1:"<<pthread_self()
            <<"  gNumber="<<gNumber<<endl;
        flag=false;
        cond.notify();
    }
    return NULL;//void * 是可以返回任意类型的值的指针,必须要返回指针
}


void * func2(void *)
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
        cout<<"subThread2:"<<pthread_self()
            <<"  gNumber="<<gNumber<<endl;
        flag=true;
        cond.notify();
    }

    return NULL;
}



int main()
{
    pthread_t pth1,pth2;
    pthread_create(&pth1,NULL,func1,NULL);
    pthread_create(&pth2,NULL,func2,NULL);

    pthread_join(pth1,NULL);
    pthread_join(pth2,NULL); // 第二个参数的传参应该是void** ，用不到直接传NULL
    
    return 0;
}

