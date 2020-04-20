#include "Acceptor.h"
#include <unistd.h>


namespace wd{

Acceptor::Acceptor(const string & ip,unsigned short port)
    :_sock()
     ,_addr(ip,port)
{

}


Acceptor::Acceptor(unsigned short port)
    :_sock()
     ,_addr(port)
{

}

void Acceptor::ready(){
    setReuseAddr();
    setReusePort();
    bind();
    listen();
}

int Acceptor::fd() const
{//这里的fd全部使用的是socket套接字建立之后的
    return _sock.fd();
}


void Acceptor::bind(){
    int ret = ::bind(fd(), (const struct sockaddr *)_addr.getInetaddr(), sizeof(_addr)) ;
    if(ret == -1)
    {
        ::close(fd());
        ::perror("bind");
    }
}

void Acceptor::listen(){
    int ret = ::listen(fd(), 10);
    if(-1 == ret) { 
        ::close(fd());
        ::perror("listen");
    }
}

void Acceptor::setReuseAddr()
{
    int reuse = 1;
    if(setsockopt(fd(), SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int))) {
        perror("setsockopt");
    }

}

void Acceptor::setReusePort()
{
    int reuse = 1;
    if(setsockopt(fd(), SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(int))) {
        perror("setsockopt");
    }

}

int Acceptor::accept()
{
    int peerfd = ::accept(fd(), nullptr, nullptr);                                                                 
    if(peerfd == -1) {
        ::perror(">> accept");
    }
    return peerfd;
}











}//end of namespace wd
