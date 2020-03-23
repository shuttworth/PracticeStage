#include "Acceptor.h"
#include "TcpConnection.h"

#include <unistd.h>
#include <iostream>


using std::cout;
using std::endl;

void test0(void)
{
    wd::Acceptor acceptor("192.168.209.128",8888);
    acceptor.ready();

    int peerfd = acceptor.accept();
    wd::TcpConnection conn(peerfd);
    cout<<conn.toString()<<" has connect! "<<endl;

    string msg = conn.receive();
    cout<<">>server receive "<<msg<<endl;
    conn.send(msg);
    ::sleep(2);
}

int main()
{
    test0();
    return 0;
}

