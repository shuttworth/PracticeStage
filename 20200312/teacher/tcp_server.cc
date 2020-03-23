 ///
 /// @file    tcp_server.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-12 14:53:31
 ///

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

void test0()
{
	//笔试题： 写一个程序，判断当前的计算机是大端模式存储还是小端模式存储的
	int a = 1;
	char * p = (char *)&a;
	int b = (int)(*p);
	cout << "b = " << b << endl;

	p += 3;
	cout << "执行p+=3之后:" << endl;
	b = (int)(*p);
	cout << "b = " << b << endl;
}

void test1()
{
	char buff[1024];//存在大端模式 小端模式的问题吗？？
	//答： 不存在。 大端模式和小端模式只针对于多字节类型的数据

	union test //联合体共享数据空间
	{
		int a;
		char data[4];
	};

	union test t1;
	t1.a = 1;
	int x = t1.data[0];
	int y = t1.data[3];

	//经过测试，采用的小端模式进行存储 (主机字节序)
	cout << "x = " << x << endl
		 << "y = " << y << endl;
}

#define ERROR_EXIT(msg) do{\
	::perror(msg);\
	::exit(EXIT_FAILURE);\
} while(0)

int test2()
{
	//1.创建套接字,得到一个文件描述符
	int listenfd = ::socket(AF_INET, SOCK_STREAM, 0);//TCP协议
	if(listenfd == -1) {
		::perror("socket");
		::exit(EXIT_FAILURE);
	}

	//网络地址 ==> 采用大端模式
	unsigned short port = 8888;
	string ip("192.168.30.128");
	struct sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(port);//小 ==》 大
	serveraddr.sin_addr.s_addr = inet_addr(ip.data());
	//2. 绑定网络地址
	if(-1 == bind(listenfd, 
		(const struct sockaddr *)&serveraddr, 
		sizeof(serveraddr))) 
	{
		::close(listenfd);
		ERROR_EXIT("bind");
	}

	//3. 对新连接请求进行监听 
	if(-1 == ::listen(listenfd, 10)) { //设置处于半连接状态的连接数的最大值
		::close(listenfd);
		ERROR_EXIT("listen");
	}

	//并发服务器模型之 循环(迭代)服务器
	while(1) {
	//4. 建立新连接
		cout << ">> server is about to accept a new link " << endl;
		struct sockaddr_in clientaddr;//4.1 解析对端IP和port
		socklen_t len = 0;
		::memset(&clientaddr, 0, sizeof(struct sockaddr_in));

		int peerfd = ::accept(listenfd, (struct sockaddr*)&clientaddr, &len);
		if(peerfd == -1) {
			::close(listenfd);
			ERROR_EXIT("accept");
		}
		//如果peerfd > 0 ，则新连接建立完毕，以后通过peerfd所对应的数据结构与
		//对端进行通信
		
		//peerfd//代表的就是一个建立好的连接 , 满足五元组
		//int ret = ::getpeername(peerfd, (struct sockaddr*)(&clientaddr), &len);
		int ret = 0;
		if(ret == -1) {
			perror("getpeername");
		} else {
			cout << " clientaddr len = " << len << endl;
			string clientip(inet_ntoa(clientaddr.sin_addr));
			unsigned short clientport = ntohs(clientaddr.sin_port);
			cout << " >>> server " << ip << ":" << port << " --> " 
				 << " client " << clientip << ":" << clientport
				 << " has connected!" << endl; 
		}

		//5. 进行数据的接收
		char buff[1024] = {0};//应用层接收缓冲区
		cout << " >>> before recv " << endl;
		ret = ::recv(peerfd, buff, sizeof(buff), 0);//默认情况下，是一个阻塞式函数
		cout << ">>> server recv ret = " << ret << endl;
		if(ret < 0) {
			if(ret == -1 && errno == EINTR)
				continue;
			else
				ERROR_EXIT("recv");
		} else if(ret == 0) {//连接已经断开了
			::close(peerfd);
		} else { 
			//ret > 0 表示已经接收到了对端发送的数据的长度
			//6. 对接收的数据进行处理(业务逻辑)
			//...
			cout << ">> server gets msg from client: " << buff << endl;
			//7. 进行数据的发送, 回显操作
			ret = ::send(peerfd, buff, strlen(buff), 0);
			if(ret == -1) {
				ERROR_EXIT("send");
				::close(peerfd);
			}
			//8. 断开连接
			::sleep(1);
			::close(peerfd);//关闭连接
		}
	}//end of while

	//9. 关闭服务器的监听文件描述符
	::close(listenfd);//文件描述符资源是有限的
}
 
int main(void)
{
	//test0();
	test2();
	return 0;
}
