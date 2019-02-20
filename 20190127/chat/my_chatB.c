#include "func.h"

int main(int argc,char** argv)
{
    args_check(argc,3);
    int fdw=open(argv[1],O_WRONLY);//以写的方式打开一号管道
    if(-1==fdw)
    {
        perror("open");
        return -1;
    }
    int fdr=open(argv[2],O_RDONLY);//以读的方式打开2号管道
    if(-1==fdr)
    {
        perror("open1");
        return -1;
    }
    printf("I am chat2\n");
    struct msgbuf{
        long mtype;
        char mtext[64];
    };

    int msgid;
    msgid=msgget(1000,IPC_CREAT|0600);
    if(-1==msgid)
    {
        perror("msgget");
        return -1;
    }
    struct msgbuf buf;
    buf.mtype=1;

    char buf1[128]={0};
    int ret;
    fd_set rdset;//描述符监控的读集合
    while(1)
    {
        FD_ZERO(&rdset);
        FD_SET(0,&rdset);
        FD_SET(fdr,&rdset);
        ret=select(fdr+1,&rdset,NULL,NULL,NULL);
        if(ret>0)
        {
            if(FD_ISSET(STDIN_FILENO,&rdset))
            {
                memset(buf1,0,sizeof(buf));
                ret=read(STDIN_FILENO,buf1,sizeof(buf));//读取标准输入
                if(0==ret)
                {
                    printf("this is end\n");
                    break;
                }
                write(fdw,buf1,strlen(buf1)-1);//写端管道内
            }
            if(FD_ISSET(fdr,&rdset))
            {
                memset(buf1,0,sizeof(buf1));
                ret=read(fdr,buf1,sizeof(buf1));
                if(0==ret)//写端断开，读端read返回，得到0
                {
                    printf("byebye\n");
                    break;
                }
                strcpy(buf.mtext,buf1);
                int ret=msgsnd(msgid,&buf,strlen(buf1)-1,0);
                if(-1==ret)
                {
                    perror("msgsnd");
                    return -1;
                }
                return 0;
            }
        }
    }
    close(fdr);
    close(fdw);
    return 0;
}
