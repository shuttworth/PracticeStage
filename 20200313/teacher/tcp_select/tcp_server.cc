 ///
 /// @file    tcp_server.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-12 14:53:31
 ///

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
using std::cout;
using std::endl;
using namespace std;

#define ERROR_EXIT(msg) do{\
	::perror(msg);\
	::exit(EXIT_FAILURE);\
} while(0)


int create_tcp_socket()
{
	int listenfd = ::socket(AF_INET, SOCK_STREAM, 0);//TCP协议
	if(listenfd == -1) {
		ERROR_EXIT("socket");
	}
	return listenfd;
}

void set_reuse_addr(int fd, int on) 
{
	socklen_t reuse = on;
	if(setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (const void *)&reuse, sizeof(socklen_t))) {
		ERROR_EXIT("setsockopt");
	}
}

int bind_inet_addr(int fd, const char * ip, unsigned short port)
{
	struct sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(port);
	serveraddr.sin_addr.s_addr = inet_addr(ip);

	int ret = bind(fd, (const struct sockaddr *)&serveraddr, sizeof(serveraddr)) ;
	if(ret == -1)
	{
		::close(fd);
		ERROR_EXIT("bind");
	}
	return ret;
}

int mylisten(int fd) 
{
	int ret = ::listen(fd, 10);
	if(-1 == ret) { 
		::close(fd);
		ERROR_EXIT("listen");
	}
	return ret;
}

int my_accept(int fd) 
{
	int peerfd = ::accept(fd, nullptr, nullptr);
	if(peerfd == -1) {
		::close(fd);
		::perror("accept");
	}
	return peerfd;
}


int handle_new_connection(int listenfd)
{
	cout << ">>> server is about to accept a new link " << endl;
	int peerfd = my_accept(listenfd);
	cout << ">>> server serve client with fd = " << peerfd << endl;
	
	socklen_t len = sizeof(struct sockaddr_in);

	struct sockaddr_in clientaddr;//4.1 解析对端IP和port
	::memset(&clientaddr, 0, sizeof(struct sockaddr_in));
	int ret = ::getpeername(peerfd, (struct sockaddr*)(&clientaddr), &len);

	struct sockaddr_in serveraddr;
	ret = ::getsockname(peerfd, (struct sockaddr*)&serveraddr, &len);

	if(ret == -1) {
		perror("getpeername");
	} else {
		cout << " clientaddr len = " << len << endl;

		string serverip(inet_ntoa(serveraddr.sin_addr));
		unsigned short serverport = ntohs(serveraddr.sin_port);
		
		string clientip(inet_ntoa(clientaddr.sin_addr));// 32位二进制的地址 ==》点分十进制IP地址
		unsigned short clientport = ntohs(clientaddr.sin_port);//大端模式 ==》 小端模式

		cout << ">>> " << serverip << ":" << serverport << " --> " 
			 << clientip << ":" << clientport
			 << " has connected!" << endl; 
	}
	return peerfd;
}

void handle_client_message(int peerfd, fd_set * rfds) 
{
	//5. 对已经建立好的连接进行数据的接收
	char buff[1024] = {0};//应用层接收缓冲区
	cout << " >>> before recv " << endl;
	int ret = ::recv(peerfd, buff, sizeof(buff), 0);//默认情况下，是阻塞函数
	cout << ">>> server recv ret = " << ret << endl;
	if(ret < 0) {
		if(ret == -1 && errno == EINTR)
			return;
		else
			::perror("recv");
	} else if(ret == 0) {//连接已经断开了
		::close(peerfd);
		FD_CLR(peerfd, rfds);
	} else { 
		//6. 对接收的数据进行处理(业务逻辑)
		cout << ">> server gets msg from client: " << buff << endl;
		//7. 进行数据的发送, 回显操作
		ret = ::send(peerfd, buff, strlen(buff), 0);
		if(ret == -1) {
			::perror("send");
			::close(peerfd);
		}
		//8. 断开连接
		::sleep(1);
		::close(peerfd);//关闭连接, 回收文件描述符
		FD_CLR(peerfd, rfds);
	}
}

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

void test0()
{
	int listenfd = create_tcp_socket();
	cout << " >>>> server listenfd  = " << listenfd << endl;

	set_reuse_addr(listenfd, 1);//将网络地址设置成可以重用的

	string ip("192.168.30.128");
	unsigned short port = 8888;
	bind_inet_addr(listenfd, ip.data(), port);
	mylisten(listenfd);


	//并发服务器模型之IO复用select
	fd_set rfds;//读事件的fd_set
	FD_ZERO(&rfds);
	FD_SET(listenfd, &rfds);//将Listenfd添加到select的监听队列中
	struct timeval tv;
	tv.tv_sec = 5;
	tv.tv_usec = 0;
	while(true) {
		int ready = select(1024, &rfds, nullptr, nullptr, nullptr);//阻塞式函数
		//int ready = select(1024, &rfds, nullptr, nullptr, &tv);//阻塞式函数
		cout << ">>> select retval = " << ready << endl;
		if(ready == -1 && errno == EINTR) {
			continue;
		} else if(ready == -1) {
			ERROR_EXIT("select");
		} else if(ready == 0) {
			cout << ">> select timeout!" << endl;
			continue;
		} else { //ready > 0
			for(int fd = 0; fd < 1024; ++fd) {
				if(FD_ISSET(fd, &rfds) && (fd == listenfd)) {
					//处理新连接
					int peerfd = handle_new_connection(listenfd);
					set_non_block(peerfd);//设置成非阻塞的
					FD_SET(peerfd, &rfds);
				}
				if(FD_ISSET(fd, &rfds) && (fd != listenfd)) {
					//处理已经创建好的连接
					handle_client_message(fd, &rfds);
				}
			}//end of for
		}
	}//end of while
	::close(listenfd);
	FD_CLR(listenfd, &rfds);
}
 
int main(void)
{
	test0();
	return 0;
}
