#pragma once
#include <vector>
#include <map>
#include <memory>
#include <sys/epoll.h>
using std::map;
using std::vector;
using std::shared_ptr;

namespace  wd{

class Acceptor;
class TcpConnection;

class EventLoop
{
public:
    EventLoop(Acceptor & acceptor);
    ~EventLoop();

    void loop();
    void unloop();

private:
    int createEpollFd();
    void addEpollReadFd(int);
    void delEpollReadFd(int);

    void waitEpollFds();
    void handleNewConnection();
    void handleMessage(int );

private:
    int _efd;
    Acceptor & _acceptor; //用到监听的listenfd
    map<int, shared_ptr<TcpConnection>> _conns;//map为何这么使用？同时照顾到peerfd和智能指针
    vector<struct epoll_event> _eventsList; //装载处理事务的数组
    bool _isLooping;

};


}//end of namespace wd
