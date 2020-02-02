#include "tranfile.h"
int tranFile(int new_fd,char *name)
{
    train t;
    int ret;
    //发送文件名
    strcpy(t.buf,name);
    t.dataLen=strlen(name);
    ret=send_n(new_fd,(char*)&t,4+t.dataLen);
    if(-1==ret)
    {
        close(new_fd);
        printf("client close\n");
        return -1;
    }
    //发文件内容
    int fd=open(name,O_RDONLY);
    //发送大小
    struct stat statbuf;
    fstat(fd,&statbuf);
    memcpy(t.buf,&statbuf.st_size,sizeof(statbuf.st_size));
    t.dataLen=sizeof(statbuf.st_size);
    ret=send_n(new_fd,(char*)&t,4+t.dataLen);
    if(-1==ret)
    {
        close(new_fd);
        printf("client close\n");
        return -1;
    }  
    t.dataLen=read(fd,t.buf,sizeof(t.buf));
    while(t.dataLen>0)
    {
        ret=send_n(new_fd,(char*)&t,4+t.dataLen);
        if(-1==ret)
        {
            close(new_fd);
            printf("client close\n");
            return -1;
        }
    }
    send_n(new_fd,(char*)&t,4+t.dataLen);
    close(new_fd);
    return 0;
}

