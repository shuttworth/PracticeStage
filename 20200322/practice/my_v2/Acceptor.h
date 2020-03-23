#pragma once

#include "InetAddress.h"
#include "Socket.h"


namespace  wd{

class Acceptor
{
public:
    Acceptor(const string & ip,unsigned short port) ;
    Acceptor(unsigned short port);

    void ready();
    int accept();
    int fd() const;

private:
    void listen();
    void bind();
    void setReuseAddr();
    void setReusePort();

private:
    Socket _sock;
    InetAddress _addr;
};


} // end of namespace wd;
