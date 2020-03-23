#include "Acceptor.h"
/* #include "TcpConnection.h" */
#include "EventLoop.h"

#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;

void test0(void)
{
    wd::Acceptor acceptor("192.168.209.128",8888);
    acceptor.ready();

    wd::EventLoop eventloop(acceptor);
    eventloop.loop();

    //没有写unloop的情况

#if 0
    int peerfd = acceptor.accept();
    wd::TcpConnection conn(peerfd);
    cout<<conn.toString()<<" has connect! "<<endl;

    string msg = conn.receive();
    cout<<">>server receive "<<msg<<endl;
    conn.send(msg);
    ::sleep(2);
#endif
}

int main()
{
    test0();
    return 0;
}

