#include "InetAddress.h"
#include <string.h>


namespace  wd{

InetAddress::InetAddress(const string & ip,unsigned short port)
{
    ::memset(&_addr,0,sizeof(_addr));
    _addr.sin_family = AF_INET;
    _addr.sin_addr.s_addr = inet_addr(ip.data());
    _addr.sin_port = htons(port);
}

InetAddress::InetAddress(unsigned short port)
{
    ::memset(&_addr,0,sizeof(_addr));
    _addr.sin_family = AF_INET;
    _addr.sin_addr.s_addr = INADDR_ANY;
    _addr.sin_port = htons(port);
}

string  InetAddress::ip() const
{
    return string(inet_ntoa(_addr.sin_addr));//char *inet_ntoa(struct in_addr inaddr); 
}

unsigned short InetAddress::port() const
{
    return ntohs(_addr.sin_port);
}



}//end of namespace wd



