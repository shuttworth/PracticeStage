 ///
 /// @file    Eventfd.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-15 11:41:38
 ///
 
#include "Eventfd.h"

#include <unistd.h>
#include <errno.h>
#include <poll.h>
#include <sys/eventfd.h>

#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

Eventfd::Eventfd(EventfdCallback && callback)
: _fd(createEventfd())
, _callback(std::move(callback))
, _isStarted(false)
{

}

Eventfd::~Eventfd()
{
	if(_isStarted) {
		stop();
	}
}

//运行在子线程
void Eventfd::start()
{
	struct pollfd pfd;
	pfd.fd = _fd;
	pfd.events = POLLIN;

	_isStarted = true;
	while(_isStarted) {
		int ready = ::poll(&pfd, 1, 6000);//定时器结合poll的使用
		if(ready == -1 && errno == EINTR)
			continue;
		else if (ready == -1) {
			perror(">> poll");
			exit(EXIT_FAILURE);
		} else if(ready == 0) {
			cout << ">> poll timeout!" << endl;
		} else {
			if(pfd.fd == _fd && (pfd.revents & POLLIN)) {
				//对读事件进行处理
				handleRead();
				//执行任务
				if(_callback)
					_callback();
			}
		}
	}
}

void Eventfd::stop()
{
	if(_isStarted) {
		_isStarted = false;
	}
}

void Eventfd::wakeup()
{
	uint64_t one = 1;
	int ret = ::write(_fd, &one, sizeof(one));
	if(ret != sizeof(one)) {
		::perror(">> write");
	}
}

int Eventfd::createEventfd()
{
	int fd = ::eventfd(1, 0);
	if(fd == -1) {
		perror(">> timerfd_create");
	}
	return fd;
}

void Eventfd::handleRead()
{
	uint64_t howmany = 0;
	int ret = ::read(_fd, &howmany, sizeof(uint64_t));
	if(ret != sizeof(howmany)) {
		perror(">> read");
	}
}

}//end of namespace wd
