#include "TcpConnection.h"
#include <iostream>
#include <sstream>
using std::cout;
using std::endl;

namespace  wd {

TcpConnection::TcpConnection(int peerfd)
:_sock(peerfd)
,_localAddr(localInetAddr())
,_peerAddr(peerInetAddr())
,_socketIO(peerfd)
,_isShutDownWrite(false)
{
    _sock.nonblock();
}

TcpConnection::~TcpConnection(){
    shutdown();
    cout<<toString()<<" has closed "<<endl;
}

string TcpConnection::receive(){
    char buff[65536] = {0};//栈空间开辟，O(1)                                                                          
    ::memset(buff, 0, 66636);
    int ret = _socketIO.readline(buff, 65536);
    //根据ret的返回值，做相应处理
    if(ret == 0) {//连接断开
        return string();
    }else {
        return string(buff);
    }   
}

void TcpConnection::send(const string & msg){
    int ret = _socketIO.writen(msg.data(), msg.size());
    if(ret != (int)msg.size()) {
        perror("send");
        //LogInfo("send msg error");
    }
}





void TcpConnection::shutdown()
{
    if(!_isShutDownWrite)
    {
        _sock.shutdownWrite();
        _isShutDownWrite = true;
    }
}

string TcpConnection::toString() const
{
    std::ostringstream oss;
    oss<<_localAddr.ip()<<":"<<_localAddr.port()<<"--->"
        <<_peerAddr.ip()<<":"<<_peerAddr.port();
    return oss.str();
}


bool TcpConnection::isclosed()
{
   return _socketIO.isClosed(); 
}

InetAddress TcpConnection::localInetAddr()
{
    struct sockaddr_in localaddr;                                                                                     
    socklen_t len = sizeof(struct sockaddr_in);
    int ret = ::getsockname(_sock.fd(), (struct sockaddr*)&localaddr, &len);
    if(-1 ==ret )
    {
        perror("getsockname");
    }
    return InetAddress(localaddr);
}


InetAddress TcpConnection::peerInetAddr()
{
    struct sockaddr_in peeraddr;                                                                                     
    socklen_t len = sizeof(struct sockaddr_in);
    int ret = ::getpeername(_sock.fd(), (struct sockaddr*)&peeraddr, &len);
    if(-1 ==ret )
    {
        ::perror("getsockname");
    }
    return InetAddress(peeraddr);
}


}//end of namespace wd
