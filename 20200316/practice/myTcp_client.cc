#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#include <iostream>
#include <string>

using std::cin;
using std::endl;
using std::string;
using std::cout;


#define ERROR_EXIT(msg) do{\
    ::perror(msg);\
    ::exit(EXIT_FAILURE);\
}while(0)


int tcp_init(const char * ip,int port)
{
    int clientfd = socket(AF_INET,SOCK_STREAM,0);
    if(clientfd == -1)
    {
        ERROR_EXIT("create_socket");
        // return;
    }

    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = ::inet_addr(ip);//转成32位网络字节序，大端 
    serveraddr.sin_port = htons(port); //转成usigned short int

    cout<<">>> client server is ready to connect"<<endl;
    int ret = ::connect(clientfd,
                        (struct sockaddr *)&serveraddr,
                        (int)sizeof(serveraddr));
    if(-1 == ret){
        ERROR_EXIT("connect");
        close(clientfd);
    }
    return clientfd;
}


void tcp_handle(int clientfd)
{
    cout<<">> client <---> server has connected!"<<endl;
    cout<<">> pls input some data:"<<endl;

    while(true)//ctrl+c 结束任务
    {
        string data;
        cin>>data;

        int  ret = ::send(clientfd,data.data(),data.size(),0);
        if(ret == -1)
        {
            ERROR_EXIT("send");
            close(clientfd);
        }
    
        char buff[1024] = {0};
        ret = ::recv(clientfd,buff,sizeof(buff),0);
        if(-1 == ret)
        {
            ERROR_EXIT("recv");
            close(clientfd);
        }   
        else if(ret ==0 )
        {
            ::close(clientfd);
        }
        else {
            cout<<">> client receive "<<ret<<endl;
            cout<<">> receive data : "<<buff<<endl;
        }
    }
    ::close(clientfd);
}




void client_test()
{
    int clientfd = tcp_init("192.168.209.128",8888);
    cout << " >> client <---> server has connected!" <<endl;
    cout << " >> pls input some data:" << endl;
    tcp_handle(clientfd);
}

int main()
{
    client_test();
    return 0;
}










