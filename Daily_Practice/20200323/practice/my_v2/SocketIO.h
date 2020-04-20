#pragma once



namespace  wd {


class SocketIO
{
public:
    SocketIO(int fd)
    :_fd(fd)
    {}

    int readn( char * buff,int len);
    int writen(const  char * buff,int len);

    int readline( char * buff,int maxlen);
    bool isClosed();
private:
    int recvPeek(char * buff,int len);
    int _fd;
};


}//end of namespace wd
