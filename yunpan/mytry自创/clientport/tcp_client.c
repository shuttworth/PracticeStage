#include "func.h"
#include "tranfile.h"

int recv_n(int sfd,char* ptran,int len);
int main(int argc,char *argv[])
{
    args_check(argc,3);
    int socketfd=socket(AF_INET,SOCK_STREAM,0);
    if(-1==socketfd)
    {
        perror("socket");
        return -1;
    }
    printf("socketfd=%d\n",socketfd);
    struct sockaddr_in ser;
    memset(&ser,0,sizeof(ser));
    ser.sin_family=AF_INET;
    ser.sin_port=htons(atoi(argv[2]));
    ser.sin_addr.s_addr=inet_addr(argv[1]);
    int ret,len;
    ret=connect(socketfd,(struct sockaddr*)&ser,sizeof(struct sockaddr));
    if(-1==ret)
    {
        perror("connect");
        return -1;
    }//上述，连接建立成功
    printf("connect success\n");
    fd_set fdset;
    int fd,flag=0;
    int readret,sendret;
    char buf[1000]={0};
    train t;
    while(1)
    {
        FD_ZERO(&fdset);
        FD_SET(STDIN_FILENO,&fdset);
        FD_SET(socketfd,&fdset);
        ret=select(socketfd+1,&fdset,NULL,NULL,NULL);
        if(-1==ret)
        {
            printf("select error");
            return -1;
        }
        if(ret>0)
        {
            if(FD_ISSET(STDIN_FILENO,&fdset))
            {
                memset(buf,0,sizeof(buf));
                memset(&t,0,sizeof(t));
                readret=read(STDIN_FILENO,t.buf,sizeof(t.buf));
                if(readret<=0)
                {
                    printf("read error");
                    return -1;
                }t.dataLen=strlen(t.buf)-1;
                sendret=send_n(socketfd,(char*)&t,t.dataLen+4);
                system("clear");
                if(sendret==-1)
                {
                    printf("send error\n");
                    goto end;
                }
                if(strncmp(t.buf,"ls",2)==0)
                {
                    while(1)
                    {
                        memset(&t,0,sizeof(t));
                        ret=recv_n(socketfd,(char*)&t.dataLen,sizeof(int));
                        if(t.dataLen==-1)
                        {
                            printf("error path\n");
                            break;
                        }
                        if(ret==-1)
                        {
                            goto end;
                            break;
                        }if(t.dataLen==0) break;//发送完毕
                        ret=recv_n(socketfd,t.buf,t.dataLen);
                        if(-1==ret)
                        {
                            goto end;
                        }
                        printf("%s",t.buf);
                    }
                    if(strncmp(t.buf,"pwd",3)==0)
                    {
                        memset(&t,0,sizeof(t));
                        ret=recv_n(socketfd,(char*)&t.dataLen,sizeof(int));
                        if(-1==ret)
                        {
                            printf("recv 4 error\n");
                            goto end;
                        }ret=recv_n(socketfd,t.buf,t.dataLen);
                        //先收到小火车的长度，再收到小火车的内容
                        if(-1==ret)
                        {
                            printf("recv datalen error\n");
                            goto end;
                        }
                        printf("%s\n",t.buf);
                    }
                    if(strncmp("cd",t.buf,2)==0)
                    {
                        memset(&t,0,sizeof(t));
                        ret=recv_n(socketfd,(char*)&t.dataLen,sizeof(int));
                        if(-1==ret)
                            goto end;
                        if(t.dataLen!=-1)
                            ret= recv_n(socketfd,t.buf,t.dataLen);
                        if(-1==ret)
                            goto end;
                        if(t.dataLen!=-1)
                            printf("当前路径:%s\n",t.buf);
                        else
                            printf("输入路径有误!\n");
                    }
                    if(strncmp("puts",t.buf,4)==0)
                    {
                        ret=tranFile(socketfd);
                        if(-1==ret)
                        {
                            goto end;
                        }else{
                            printf("upload success\n");
                        }
                    }
                   
                   // if(strncmp("gets",t.buf,4)==0)
                   // {
                   //     off_t cursize=0;
                   //     ret=;
                   // }


                    if(strncmp(buf,"rm ",3)==0)
                    {
                        recv(socketfd,&flag,sizeof(int),0);
                        if(flag==0)
                        {
                            printf("remove success\n");
                        }
                        else if(flag==-1)
                        {
                            printf("remove failed!\n");
                        }
                    }
                    // recv(socketfd,&cmdflag,sizeof(int),0);
                    // if(0==cmdflag)
                    // {
                    //     printf("instrucment illegal\n");
                    // }
                    // readret=0;
                    // flushflag=0;
                }
            }
        }
end:   
        close(socketfd);
        exit(0);
    }
}
