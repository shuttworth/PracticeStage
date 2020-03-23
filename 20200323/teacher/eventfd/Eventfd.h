 ///
 /// @file    Eventfd.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-15 11:38:17
 ///
 
#ifndef __WD_TIMER_H__
#define __WD_TIMER_H__

#include <functional>

namespace wd
{

class Eventfd
{
public:
	using EventfdCallback = std::function<void()>;
	Eventfd(EventfdCallback && callback);
	~Eventfd();

	void start();
	void stop();

	void wakeup();
private:
	int createEventfd();
	void handleRead();
	
private:
	int _fd;
	bool _isStarted;
	EventfdCallback _callback;
};

}//end of namespace wd


#endif
