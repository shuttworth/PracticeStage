#include "SocketIO.h"
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;
namespace wd{

bool SocketIO::isClosed()
{
    int nret = 0;                                                                                                            
    char buff[1024];
    ::memset(buff, 0, sizeof(buff));
    do {
        nret = ::recv(_fd, buff, sizeof(buff), MSG_PEEK);

    }while(nret == -1 && errno == EINTR);
    return (nret == 0);

}


int SocketIO::readn( char * buff,int len )
{
    char * p = buff;
    int left = len;
    while(left>0)
    {
        int ret = ::read(_fd,p,left);
        if(-1 ==ret && errno == EINTR)
        {
            continue;
        }
        else if(-1 == ret)
        {
            ::perror("read");
            break;
        }
        else if(ret ==0){
            break;
        }else if(ret>0)
        {
            p+=ret;
            left-=ret;
        }
    }
    return len - left;
}

int SocketIO::writen(const char * buff,int len){
    const char * p = buff;
    int left = len;
    while(left>0)
    {
        int ret = ::write(_fd,p,left);
        if(-1 ==ret && errno == EINTR)
        {
            continue;
        }
        else if(-1 == ret)
        {
            ::perror("write");
            break;
        } else {
            p+=ret;
            left-=ret;
        }
    }
    return len - left;

}

int SocketIO::recvPeek(char * buff,int len)
{
    int ret = 0;
    do{
        ret = ::recv(_fd,buff,len,MSG_PEEK);//只查看,并未从缓冲区移走
    }while(ret == -1 && errno == EINTR);
    return ret;
}

int SocketIO::readline( char * buff,int maxlen ){
    int left = maxlen -1;//长度去掉\0
    char * p = buff;
    int total = 0;
    while(left>0){
        int ret = recvPeek(p,left);//预览数据，找到\n
        if(ret<=0){
            return ret;
        }
        cout<<"recv peek "<<ret<<" bytes data. "<<endl;
        for(int idx= 0;idx<ret;++idx)
        {
            if(p[idx]=='\n'){
                int size = idx +1 ; //idx-0+1个数据
                readn(p,size);//真正从内核开始拷贝数据内容
                total += size;//更新
                p+=size;//更新
                *p ='\0';//
                return total;
            }
        }
        //没有找到\n,那就把所有内容都read
        readn(p,ret);
        total+=ret;
        p+=ret;
        left-=ret;
    }
    *p='\0';
    return total;

}






}//end of namespace wd
