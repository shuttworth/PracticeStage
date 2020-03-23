#include "Socket.h"
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/socket.h>


namespace  wd{

Socket::Socket()
{
    _fd = ::socket(AF_INET, SOCK_STREAM, 0);//TCP协议                                                         
    if(_fd == -1) {
        perror("socket");
    }   
}

Socket::Socket(int fd)
:_fd(fd)
{}

Socket::~Socket()
{
    ::close(_fd);
}

void Socket::shutdownWrite() 
{
    if(::shutdown(_fd,SHUT_WR)){
        ::perror(">> shutdown");
    }
}

int Socket::fd() const
{
    return _fd;
}

void Socket::nonblock()
{
    int flags = ::fcntl(_fd, F_GETFL, 0);                                                                               
    if(flags == -1) {
        perror("fcntl");
    }
    int ret = ::fcntl(_fd, F_SETFL, O_NONBLOCK | flags);
    if(ret == -1) {
        perror("fcntl");
    }
}


}
