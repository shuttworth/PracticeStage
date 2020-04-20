#include "EventLoop.h"
#include "Acceptor.h"
#include "TcpConnection.h"
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;

namespace wd{


EventLoop::EventLoop(Acceptor & acceptor)
:_efd(createEpollFd())
,_acceptor(acceptor)
,_eventsList(1024)
,_isLooping(false)
{
    addEpollReadFd(_acceptor.fd());//构造函数里面就已经把监听的listenfd加入epoll_ctl读事件当中了:w
}    

EventLoop::~EventLoop()
{
    ::close(_efd);
}

void EventLoop::loop(){
    _isLooping = true;
    while(_isLooping){
        waitEpollFds();
    }
}


void EventLoop::unloop()
{
    if(_isLooping){
        _isLooping = false;
    }
}


int EventLoop::createEpollFd()
{
    int efd = ::epoll_create1(0);
    if(-1 == efd ){
        perror("epoll_create1");
    }
    return efd;
}


void EventLoop::addEpollReadFd(int fd)
{
	struct epoll_event value;
	value.data.fd = fd;
	value.events = EPOLLIN;
	int ret = epoll_ctl(_efd, EPOLL_CTL_ADD, fd, &value);
	if(ret == -1) {
		perror(">> addEpollReadFd");
	}
}


void EventLoop::delEpollReadFd(int fd)
{
	struct epoll_event value;
	value.data.fd = fd;
	value.events = EPOLLIN;
	int ret = epoll_ctl(_efd, EPOLL_CTL_ADD, fd, &value);
	if(ret == -1) {
		perror(">> delEpollReadFd");
	}
}

void EventLoop::waitEpollFds()//核心内容
{
    int nready;
    do{
        nready = ::epoll_wait(_efd,&_eventsList[0],_eventsList.size(),5000);
    }while(nready ==-1 && errno ==EINTR);

    if(nready == -1){
        perror("epoll_wait");
    }else if(nready == 0){
        perror("epoll_wait timeout");
    }else {
        if(nready == (int)_eventsList.size())
        {
            _eventsList.resize(2* nready);
        }
        for(int idx= 0 ;idx<nready ;++idx)
        {
            if(_eventsList[idx].data.fd == _acceptor.fd()) //准备建立新连接
            {
                handleNewConnection();
            }
            else if(_eventsList[idx].events == EPOLLIN) //接收到数据，读socket
            {
                handleMessage(_eventsList[idx].data.fd);
            }
        }
    }
}

void EventLoop::handleNewConnection()
{
	cout << ">>> server is about to accept a new link " << endl;
    int peerfd = _acceptor.accept();
	cout << ">>> server serve client with fd = " << peerfd << endl;
	/* set_non_block(peerfd);//设置成非阻塞的 */
	addEpollReadFd(peerfd);

    shared_ptr<TcpConnection> conn(new TcpConnection(peerfd));
    _conns.insert(make_pair(peerfd,conn)) ;  
    cout <<conn->toString() <<" has connected!" << endl;
}


void EventLoop::handleMessage(int peerfd)
{//_conn是个被智能指针托管的TcpConnection对象
    auto iter = _conns.find(peerfd);
    if(iter!=_conns.end())
    {
        //先判断是否断开
        auto conn = iter->second;
        bool closed = conn ->isclosed();
        if(!closed)
        {
            //连接没有关闭，收到数据
            string msg = conn->receive();
            cout<<">> server receive: "<<msg<<endl;
            conn->send(msg); //回写操作
        }else{
            //连接断开
            cout<<">>"<<conn->toString()<<" has closed! "<<endl;
            delEpollReadFd(peerfd);
            _conns.erase(peerfd);
        }
    
    }
}




}//end of namespace wd
