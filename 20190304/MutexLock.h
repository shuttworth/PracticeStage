#ifndef __WD_MUTEX_H__//ifndef
#define __WD_MUTEX_H__//宏的写法：__命名空间_类名_H__  ，通用写法，支持跨平台

#include <pthread.h>

namespace wd
{

class MutexLock
{
public:
    MutexLock();
    ~MutexLock();

    MutexLock(const MutexLock &)=delete;
    MutexLock & operator=(const MutexLock &)=delete;//c++11

    void lock();
    void unlock();

    pthread_mutex_t * getMutexLockPtr()
    {
        return &_mutex;
    }
private:
    pthread_mutex_t _mutex;

};

class MutexLockGuard
{
    public:
        MutexLockGuard( MutexLock &mutex)
        :_mutex(mutex)
        {
            _mutex.lock();
        }

        ~MutexLockGuard()
        {
            _mutex.unlock();
        }


    private:
        MutexLock & _mutex;
};//class 后面的；不可少


}//end of namespace 
#endif




