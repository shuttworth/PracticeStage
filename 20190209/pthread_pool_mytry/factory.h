#ifndef __FACTORY_H__
#define __FACTORY_H__
#include "head.h"
#include "work_que.h"
#include "tranfile.h"
typedef void* (*threadfunc_t)(void*);
typedef struct{
    pthread_t *pthid;//不知道需要多少线程，所以定义线程的指针
    int threadNum;
    Que_t que;
    pthread_cond_t cond;
    threadfunc_t downFileFunc;
    short startflag;
}Factory,*pFactory;
//为了程序的可扩展性，需要先写结构体，哪怕只有一个内容
void factoryInit(pFactory pf,int threadNum,int capacity,threadfunc_t threadfunc);
void factoryStart(pFactory);
int tcpInit(int *sfd,char* ip,char* port);
#endif
