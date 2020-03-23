#pragma once

#include <functional>

namespace  wd 
{

class Timer
{
public:
    using TimerCallback = std::function<void()>;//将无参数返回值void型的都注册了
    Timer(TimerCallback && callback,int initialTime,int periodicTime);
    ~Timer();

    void start();
    void stop();

private:
    int createTimerfd();
    void setTimerfd(int initialTime,int periodicTime);
    void handleRead();

private:
    int _fd;
    int _initialTime;
    int _periodicTime;
    TimerCallback _callback;
    bool _isStart;



};



}//end of namespace wd 


