#include "work_que.h"

void queInsert(pQue_t pq,pNode_t pnew)
{
    //队列的实现是尾插法头部删除法
    if(NULL==pq->queHead)
    {
        pq->queHead=pnew;
        pq->queTail=pnew;
    }else
    {
        pq->queTail->ndNext=pnew;
        pq->queTail=pnew;
    }
    pq->queSize++;
}//queInsert 处于加解锁之间，只写逻辑，不写别的东
int queGet(pQue_t pq,pNode_t* pget)
{
    if(!pq->queSize)
    {
        return -1;
    }
    *pget=pq->queHead;
    pq->queHead=pq->queHead->ndNext;
    pq->queHead--;
}





