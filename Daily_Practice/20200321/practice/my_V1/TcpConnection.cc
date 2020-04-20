#include "TcpConnection.h"
#include <string.h>

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
    int ret = ::getsockname(_sock.fd(), (struct sockaddr*)&peeraddr, &len);
    if(-1 ==ret )
    {
        perror("getsockname");
    }
    return InetAddress(peeraddr);

}

void TcpConnection::send(const string & msg){
    int ret = _socketIO.writen(msg.data(), msg.size());
    if(ret != (int)msg.size()) {
        perror("send");
        //LogInfo("send msg error");
    }

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





}//end of namespace wd
