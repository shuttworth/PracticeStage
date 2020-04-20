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
#include <pthread.h>

#include <iostream>
#include <functional>
#include <vector>
using std::cout;
using std::endl;
using namespace std;

#define ERROR_EXIT(msg) do{\
	::perror(msg);\
	::exit(EXIT_FAILURE);\
} while(0)


struct thread_data{
	const char * ip;
	unsigned port;
	int peerfd;
};

struct thread_data pth_data;//全局,创造一个thread_data类型的结构体，名字叫pth_data

//子线程的处理过程
void * process_connection(void * arg)
{
	struct thread_data * pdata = (struct thread_data*)(arg);
	struct thread_data local_pthread_data;
	local_pthread_data.ip = pdata->ip;
	local_pthread_data.port = pdata->port;
	local_pthread_data.peerfd = pdata->peerfd;
	cout << ">>>> subthread " << pthread_self() << endl;

	int peerfd = local_pthread_data.peerfd;//局部变量

	//peerfd//代表的就是一个建立好的连接 , 满足五元组
	struct sockaddr_in clientaddr;//4.1 解析对端IP和port
	::memset(&clientaddr, 0, sizeof(struct sockaddr_in));
	socklen_t len = sizeof(struct sockaddr_in);
	int ret = ::getpeername(peerfd, (struct sockaddr*)(&clientaddr), &len);
	if(ret == -1) {
		perror("getpeername");
	} else {
		string clientip(inet_ntoa(clientaddr.sin_addr));// 32位二进制的地址 ==》点分十进制IP地址
		unsigned short clientport = ntohs(clientaddr.sin_port);//大端模式 ==》 小端模式
		cout << " >>>> subthread " << pthread_self() << ": " 
			 << local_pthread_data.ip << ":" << local_pthread_data.port << " --> " 
			 << clientip << ":" << clientport << " has connected!" << endl; 
	}

	//5. 进行数据的接收
	char buff[1024] = {0};//应用层接收缓冲区
	cout << " >>>> before recv " << endl;
	//如果peerfd > 0 ，则新连接建立完毕，以后都通过peerfd所对应的数据结构与
	//对端进行通信(进行数据的接收和发送)
	ret = ::recv(peerfd, buff, sizeof(buff), 0);// peerfd发生了读事件
	if(ret < 0) {
		if(ret == -1 && errno == EINTR)
			return nullptr;
		else
			ERROR_EXIT("recv");
	} else if(ret == 0) {//连接已经断开了
		::close(peerfd);
	} else { 
		//ret > 0 表示已经接收到了对端发送的数据的长度
		//6. 对接收的数据进行处理(业务逻辑)
		//...
		cout << ">>>> server gets msg from client: " << buff << endl;
		//7. 进行数据的发送, 回显操作
		ret = ::send(peerfd, buff, strlen(buff), 0);// peerfd要发生写事件
		if(ret == -1) {
			ERROR_EXIT("send");
			::close(peerfd);
		}
		//8. 断开连接
		::sleep(1);
		::close(peerfd);//关闭连接, 回收文件描述符
	}

	return nullptr;
}

int test0()
{
	//1.创建套接字,得到一个文件描述符
	int listenfd = ::socket(AF_INET, SOCK_STREAM, 0);//TCP协议
	if(listenfd == -1) {
		::perror("socket");
		::exit(EXIT_FAILURE);
	}
	cout << ">> server listenfd  = " << listenfd << endl;

	//网络地址 ==> 采用大端模式(网络字节序)
	unsigned short port = 8888;//小端模式(主机字节序)存储
	string ip("192.168.30.128");

	pth_data.ip = ip.data();
	pth_data.port = port;

	struct sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(port);//小 ==》 大
	serveraddr.sin_addr.s_addr = inet_addr(ip.data());//点分十进制IP地址 ==> 32位二进制地址
	//2. 绑定网络地址
	if(-1 == bind(listenfd, 
		(const struct sockaddr *)&serveraddr, 
		sizeof(serveraddr))) 
	{
		::close(listenfd);
		ERROR_EXIT("bind");
	}

	//3. 对新连接请求进行监听 
	if(-1 == ::listen(listenfd, 10)) { //backlog 设置处于半连接状态的连接数的最大值
		::close(listenfd);
		ERROR_EXIT("listen");
	}

	vector<pthread_t> pthreads;
	//并发服务器模型之多线程模型: 一个请求交给一个子线程处理
	int cnt = 5;
	while(cnt--) {
	//4. 建立新连接
		cout << ">> server is about to accept a new link " << endl;
		int peerfd = ::accept(listenfd, nullptr, nullptr);  //在listenfd上是有读事件发生
		if(peerfd == -1) {
			::close(listenfd);
			ERROR_EXIT("accept");
		}
		cout << ">> server serve client with peerfd = " << peerfd << endl;
		pth_data.peerfd = peerfd;//

		/////采用多线程的方式处理请求
		pthread_t pthid;//创建子线程处理请求
		if(pthread_create(&pthid, nullptr, process_connection, (void*)&pth_data)) {
			ERROR_EXIT("pthread_create");
		}
		pthreads.push_back(pthid);
		cout << ">> main thread create subthread " << pthid << endl;
	}//end of while

	cout << ">> main thread release subthreads..." << endl; 
	for(auto & pthid : pthreads) {
		pthread_join(pthid, nullptr);
	}

	//9. 关闭服务器的监听文件描述符
	::close(listenfd);//文件描述符资源是有限的
}
 
int main(void)
{
	test0();
	return 0;
}
