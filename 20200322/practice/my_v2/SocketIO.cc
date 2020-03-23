#include "SocketIO.h"
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>


namespace wd{

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
    int left = maxlen -1;
    char * p = buff;


}






}//end of namespace wd
