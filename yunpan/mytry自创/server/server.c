#include "factory.h"
#include "manage.h"
#include "reg.h"

void* threadfunc(void* p)
{
    usrInfo ui;
    train t;
    memset(&ui,0,sizeof(ui));
    memset(&t,0,sizeof(t));
    pFactory pf=(pFactory)p;
    pQue_t pq=&pf->que;
    pNode pcur;
    int ret,flag;
    while(1)
    {
        memset(&ui,0,sizeof(ui));
        pthread_mutex_lock(&pq->queMutex);
        if(!pq->queSize)//如果队列为空，子线程就睡眠
        {
            pthread_cond_wait(&pf->cond,&pq->queMutex);
        }
        ret=queGet(pq,&ui.pnd);
        pthread_mutex_unlock(&pq->queMutex);
        if(0==ret)
        {
            tranFile(pcur->ndSocketfd);
            free(pcur);
        }
        pcur=NULL;
        ret=recv_n(pcur->ndSocketfd,(char*)&t.dataLen,sizeof(int));
        if(ret==-1)
        {
            printf("client byebye...\n");
            break;
        }
        if(t.dataLen==0) break;
        recv_n(pcur->ndSocketfd,t.buf,t.dataLen);
        if(strcmp(t.buf,"ls")==0)
        {
            showDir()
        }

    }
}

int main(int argc,char **argv)
{
    args_check(argc,5);
    Factory f;
    int threadNum=atoi(argv[3]);
    int factoryCapacity=atoi(argv[4]);
    factoryInit(&f,threadNum,factoryCapacity,threadfunc);
    factoryStart(&f);
    int socketfd;
    tcpInit(&socketfd,argv[1],argv[2]);
    int new_fd,ret;
    train t;
    pQue_t pq=&f.que;
    pNode pnew;
    while(1)
    {
        new_fd=accept(socketfd,NULL,NULL);
        pnew=(pNode)calloc(1,sizeof(Node));
        pnew->ndSocketfd=new_fd;
        pthread_mutex_lock(&pq->queMutex);
        queInsert(pq,pnew);
        pthread_mutex_unlock(&pq->queMutex);
        pthread_cond_signal(&f.cond);
        char buf[1000]={0};
        ret=recv(new_fd,&t,t.dataLen+4,0);
        strncpy(buf,t.buf+4,t.dataLen);
    }
}
