#ifndef __WD_CONDITION_H__
#define __WD_CONDITION_H__

//#include"MutexLock.h"        防止头文件的循环依赖
#include <pthread.h>

namespace wd
{
class MutexLock;//类的前向声明
class Condition
{
public:
    Condition(MutexLock & mutex);
    ~Condition();
    Condition(const Condition & )=delete;
    Condition & operator=(const Condition &)=delete; 


    void wait();
    void notify();
    void notifyall();
private:
    pthread_cond_t _cond;
    MutexLock & _mutex;
};

}

#endif



