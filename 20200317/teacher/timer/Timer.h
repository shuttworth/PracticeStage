 ///
 /// @file    Timer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-15 11:38:17
 ///
 
#ifndef __WD_TIMER_H__
#define __WD_TIMER_H__

#include <functional>

namespace wd
{

class Timer
{
public:
	using TimerCallback = std::function<void()>;
	Timer(TimerCallback && callback, int initialTime, int peoriodicTime);
	~Timer();

	void start();
	void stop();
private:
	int createTimerfd();
	void setTimerfd(int initialTime, int periodicTime);
	void handleRead();
	
private:
	int _fd; //文件描述符
	int _initialTime; //初始化时间
	int _periodicTime;  //周期性时间
	TimerCallback _callback;
	bool _isStarted;
};

}//end of namespace wd


#endif
