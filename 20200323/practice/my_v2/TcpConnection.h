#pragma once

#include "InetAddress.h"
#include "Socket.h"
#include "Acceptor.h"
#include "SocketIO.h"
#include <string.h>

using std::string;

namespace  wd{

class TcpConnection
{
public:
    explicit
    TcpConnection(int);
    ~TcpConnection();
    
    void send(const string & );
    string receive();

    string toString() const; 
    void shutdown();
    bool isclosed();
private:
    InetAddress localInetAddr();
    InetAddress peerInetAddr();

private:
    Socket _sock;
    InetAddress _localAddr;
    InetAddress _peerAddr;
    SocketIO _socketIO;
    bool _isShutDownWrite;

};





}//end of namespace wd
