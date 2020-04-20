 ///
 /// @file    EventLoop.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-19 11:18:34
 ///
 
#ifndef __WD_EVENTLOOP_H__
#define __WD_EVENTLOOP_H__

#include <sys/epoll.h>

#include <vector>
#include <map>
#include <memory>
using std::vector;
using std::map;
using std::shared_ptr;

namespace wd
{

class Acceptor;
class TcpConnection;
//使用类的前向声明，而不是头文件

class EventLoop
{
public:
	EventLoop(Acceptor & acceptor);
	~EventLoop();

	void loop();
	void unloop();

private:
	int createEpollFd();
	void addEpollReadFd(int fd);
	void delEpollReadFd(int fd);

	void waitEpollFds();
	void handleNewConnection();
	void handleMessage(int peerfd);
	
private:
	int _efd;
	Acceptor & _acceptor;
	map<int, shared_ptr<TcpConnection>> _conns;
	vector<struct epoll_event> _eventsList;
	bool _isLooping;
};

}//end of namespace wd


#endif

