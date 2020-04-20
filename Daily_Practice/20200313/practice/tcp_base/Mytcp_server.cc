#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using namespace std;

#define ERROR_EXIT(msg) do{\
    ::perror(msg);\
    ::exit(EXIT_FAILURE);\
}while(0)
//EXIT_FAILURE 可以作为exit()的参数来使用，表示没有成功地执行一个程序。
//EXIT_SUCCESS 作为exit()的参数来使用，表示成功地执行一个程序。
//perror(const char * s)

int test0()
{
    //1.创建套接字，socket，得到listenfd
    int listenfd=::socket(AF_INET,SOCK_STREAM,0);//ipv4,tcp
    if(listenfd==-1){
        ERROR_EXIT("socket");
    }
    
        
    unsigned short port = 8888;
    string ip("192.168.209.128");
    struct sockaddr_in serveraddr;
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(port);//主机字节序转网络字节序
    serveraddr.sin_addr.s_addr=htonl(port);//
    //上面这一句为何按照inet写法，不懂
    

    //2.bind
    if(-1==bind(listenfd,
                (const struct sockaddr *)&serveraddr,
                sizeof(serveraddr)))
    {
        ::close(listenfd);
        ERROR_EXIT("bind");
    }


    //3.listen + while(1)
    if(-1==listen(listenfd,10)){
        ::close(listenfd);
        ERROR_EXIT("listen");
    }

    //while，迭代服务器
    while(1)
    {
        cout << ">> server is about to accept a new link "<<endl;
        struct sockaddr_in clientaddr;
        socklen_t len = 0;//这里结构体的长度，给的是0
        ::memset(&clientaddr,0,sizeof(clientaddr));

        int peerfd = ::accept(listenfd,(struct sockaddr * )&clientaddr,&len);
        if(-1==peerfd)
        {
            ::close(listenfd);
            ERROR_EXIT("accept");
        }
    
        
    
    }







    return 0;
}














int main()
{
    return 0;
}

