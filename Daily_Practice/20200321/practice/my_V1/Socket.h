#pragma once

namespace  wd{

class Socket
{
public:
    Socket();
    explicit Socket(int);
    ~Socket();

    int fd() const;

    void nonblock();
    void shutdownWrite();

private:
    int _fd;
};

}//end of namespace wd;

