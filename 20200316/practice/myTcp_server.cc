#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <iostream>
#include <functional>
#include <vector>
#include <unordered_set>
using namespace std;


#define ERROR_EXIT(msg)\
{\
    ::perror(msg);\
    ::exit(EXIT_FAILURE);\
}


int create_tcp_socket()
{
    int listenfd = ::socket(AF_INET,SOCK_STREAM,0);
    if(-1 == listenfd){
        ERROR_EXIT("socket");
    }
    return listenfd;
}

void set_reuse_addr(int fd,bool on)
{
    bool reuse = on;
    if(setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(int)))
    {
        ERROR_EXIT("setsockopt");
    }
}

void set_reuse_port(int fd,bool on)
{
    bool reuse = on;
    if(setsockopt(fd,SOL_SOCKET,SO_REUSEPORT,&reuse,sizeof(int)))
    {
        ERROR_EXIT("setsockopt");
    }
}

int my_bind(int fd,const char * ip,unsigned short port)
{
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(ip);
    serveraddr.sin_port = htons(port);

    int ret = ::bind(fd,(const struct sockaddr *)&serveraddr,sizeof(sockaddr));
    if(-1 ==ret )
    {
        ::close(fd);
        ERROR_EXIT("bind");
    }
    return ret;
}

int my_listen(int fd)
{
    int ret = ::listen(fd,10);//10是最大请求数
    if(-1 == ret)
    {
        ::close(fd);
        ERROR_EXIT("listen");
    }
    return ret;
}


int my_accept(int fd)
{
    int peerfd = ::accept(fd,nullptr,nullptr);//好奇，这里不记录的话，传空指针，那么在哪里记录呢？
    if(-1 == peerfd)
    {
        ::close(fd);
        ::perror("accept");
    }
    return peerfd;
}


int handle_new_connection(int listenfd)
{
    cout << ">>> server is about to accept a new link " << endl;
    int peerfd = my_accept(listenfd);
    cout << ">>> server serve client with fd = " << peerfd <<endl;
    return peerfd;
}


void print_connection_info(int peerfd)
{//两个核心函数是getsockname和getpeername,得到本地本地地址和对方地址的信息

    struct sockaddr_in serveraddr;
    socklen_t len = sizeof(struct sockaddr_in );
    int ret = ::getsockname(peerfd,(struct sockaddr *)&serveraddr,&len);
    //getsockname函数用于获取与某个套接字关联的本地协议地址
    //信息存在serveraddr结构体内部

    struct sockaddr_in clientaddr;
    ::memset(&clientaddr,0,sizeof(clientaddr));
    ret = ::getpeername(peerfd,(struct sockaddr *)&clientaddr,&len);
    //getpeername函数用于获取与某个套接字关联的外地协议地址
    //信息存在clientaddr结构体内部

    if(-1 == ret )
    {
        perror("getpeername");
    }else{
        cout<<"clientaddr len = "<<len<<endl;
        string serverip(inet_ntoa(serveraddr.sin_addr));
        unsigned short serverport = ntohs(serveraddr.sin_port);

        string clientip(inet_ntoa(clientaddr.sin_addr));
        unsigned short clientport = ntohs(clientaddr.sin_port);

        cout<<">>>"<<serverip <<" :"<<serverport<<"--->"
            <<clientip<<" :"<<clientport<<endl;
    }

}


void handle_client_message(int peerfd,fd_set * rfds,unordered_set<int>& client_fds)//不太懂
{
    char buff[1024]={0};
    cout<<">>> before recv"<<endl;
    int ret = ::recv(peerfd,buff,sizeof(buff),0);
    cout<<">>> server recv ret = "<<ret<<endl;
    //recv的三种返回值判断
    if(ret < 0)
    {
        if(ret ==-1&&errno==EINTR) //表示错误是由中断引起的
            return;//不太懂
        else
            ::perror("recv");
    }else if(ret==0)
    {
        print_connection_info(peerfd);
        cout<<" connection has closed! "<<endl;

        ::close(peerfd);
        FD_CLR(peerfd,rfds);//把peerfd从rfds里剔除
        client_fds.erase(peerfd);
    }else{
        cout << ">> server gets msg from client: " << buff << endl;

        ret = ::send(peerfd,buff,strlen(buff),0);
        if(ret == -1)
        {
            ::perror("send");
            ::close(peerfd);
        }
    }
}

//fcntl的用法暂且不太清楚
void set_non_block(int fd)
{
    int flags = ::fcntl(fd, F_GETFL, 0);
    if(flags == -1) {
        ERROR_EXIT("fcntl");
    }
    int ret = ::fcntl(fd, F_SETFL, O_NONBLOCK | flags);
    if(ret == -1) {
        ERROR_EXIT("fcntl");
    }
}


//把这些文件描述符全部添加到select 的轮询监听列表里
void select_fds_init(int & maxfd, fd_set * rfds, unordered_set<int>&client_fds)
{
    for(auto & fd : client_fds) {
        FD_SET(fd, rfds);   
        if(maxfd < fd) maxfd = fd;
    }
}



int tcp_server(const string & ip,unsigned short port)
{
    int listenfd = create_tcp_socket();
    cout << " >>>> server listenfd  = " << listenfd << endl;
    set_reuse_addr(listenfd, true);//将网络地址设置成可以重用的
    set_reuse_port(listenfd, true);
    
    my_bind(listenfd,ip.c_str(),port);
    my_listen(listenfd);
    return listenfd;
}


void server_test()
{
    string ip("192.168.209.128");
    unsigned short port = 8888;
    int listenfd = tcp_server(ip,port);

    //并发服务器模型之IO复用select
    fd_set rfds;//读事件的fd_set
    struct timeval tv;
    int maxfd = 1024;

unordered_set<int> client_fds;//存储的是所有已经建立连接的fd
while(true) {
            //每次调用select前都要重新设置fd和时间,
            //因为事件发生后，fd和时间都被内核修改了
    FD_ZERO(&rfds);
    FD_SET(listenfd, &rfds);

    select_fds_init(maxfd, &rfds, client_fds);
    tv.tv_sec = 5;//5秒超时
    tv.tv_usec = 0;

    int ready = select(maxfd, &rfds, nullptr, nullptr, nullptr);//阻塞式函数, 一直等
    //int ready = select(maxfd + 1, &rfds, nullptr, nullptr, &tv);//阻塞式函数, 指定
    cout << ">>> select retval = " << ready << endl;
    if(ready == -1 && errno == EINTR) {
        continue;
    } else if(ready == -1) {
        ERROR_EXIT("select");
    } else if(ready == 0) {
        cout << ">> select timeout!" << endl;
        continue;
    }else {//ready > 0
        for(int fd=0;fd<maxfd+1;++fd)
        {
            if(FD_ISSET(fd,&rfds)&&(fd==listenfd)){
                int peerfd = handle_new_connection(listenfd);        
                set_non_block(peerfd);//设置成非阻塞的
                print_connection_info(peerfd);
                cout << "has connected!" << endl;
                FD_SET(peerfd, &rfds);
                client_fds.insert(peerfd);
            }

            if(FD_ISSET(fd, &rfds) && (fd != listenfd)) {
                // 处理已经创建好的连接
                handle_client_message(fd, &rfds, client_fds);

            }

        }//end of for

    }//end of while
    ::close(listenfd);
    FD_CLR(listenfd,&rfds);
}

}



int main()
{
    server_test();
    return 0;
}






