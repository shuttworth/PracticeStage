#include "factory.h"

void* threadfunc(void *p)
{
    pFactory pf=(pFactory)p;
    pQue_t pq=&pf->que;
    pNode_t pcur;
    int ret;
    while(1)
    {
        pthread_mutex_lock(&pq->que_mutex);
        if(!pq->queSize)//如果队列为空，子线程就睡眠
        {
            pthread_cond_wait(&pf->cond,&pq->que_mutex);
        }
        ret=queGet(pq,&pcur);
        pthread_mutex_unlock(&pq->que_mutex);
        if(!ret)
        {    
            tranFile(pcur->nd_socketfd);
            free(pcur);
        }
        pcur=NULL;
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
    int new_fd;
    pQue_t pq=&f.que;
    pNode_t pnew;
    while(1)
    {
        new_fd=accept(socketfd,NULL,NULL);
        pnew=(pNode_t)calloc(1,sizeof(Node_t)) ;
        pnew->nd_socketfd=new_fd;
        pthread_mutex_lock(&pq->que_mutex);
        queInsert(pq,pnew);
        pthread_mutex_unlock(&pq->que_mutex);
        pthread_cond_signal(&f.cond);
    }
    return 0;
}

