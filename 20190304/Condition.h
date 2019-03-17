#ifndef __WD_CONDITION_H__
#define __WD_CONDITION_H__

//#include"MutexLock.h"        防止头文件的循环依赖,因为不需要使用头文件，没必要知道Mutexlock的空间
#include <pthread.h>

namespace wd
{
class MutexLock;//类的前向声明  
class Condition
{
public:
    Condition(MutexLock & mutex);//因为引用了互斥锁，所以需要初始化
    ~Condition();
    Condition(const Condition & )=delete;
    Condition & operator=(const Condition &)=delete; 


    void wait();
    void notify();
    void notifyall();
private:
    pthread_cond_t _cond;
    MutexLock & _mutex; //写成&，而不是MutexLock  _mutex，因为互斥锁不是condition 的对象成员，不会随着他的丢失而销毁,所以加上引用
};

}

#endif



