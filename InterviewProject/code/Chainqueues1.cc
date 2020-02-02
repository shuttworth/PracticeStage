#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

//链表队列
typedef int Elemtype; //方便程序后来的更改

typedef struct LinkNode{
    Elemtype data;
    struct LinkNode * next;
}LinkNode,*SLinkNode ;

typedef struct LinkQueue{
    SLinkNode front,rear;
}LinkQueue;

void InitQueue(LinkQueue &Q)
{
    Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next=NULL;
}

bool QueueEmpty(LinkQueue &Q)
{
    return Q.front==Q.rear;
}

//插入元素须在队列尾，删除元素需要在队头
void InQueue(LinkQueue &Q,Elemtype e)
{
    //插入元素，首先是要新开辟一个空间
    LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
    s->data=e;
    s->next=NULL;
    Q.rear->next=s;
    Q.rear=s; //如果是数组中的移动，下标加1即可；像链表这样的情况，需要使得给rear等指针赋值
}

bool OutQueue(LinkQueue &Q,Elemtype &e)
{
    //->专门为指针服务,通过.得到类内部的成员内容
    if(!QueueEmpty(Q))
    {
        LinkNode * p=Q.front->next;
        Q.front->next=p->next;//链表队列里的结点，只有next指针相连
        e=p->data;
        free(p);
        p=NULL;//避免野指针
        return true;
    }
    return false;
}


int main()
{
    LinkQueue q;
    Elemtype del;
    InitQueue(q);
    InQueue(q,2);
    cout<<"push 2"<<endl;
    InQueue(q,4);
    cout<<"push 4"<<endl;
    InQueue(q,6);
    cout<<"push 6"<<endl;
    OutQueue(q,del);
    cout<<"pop "<<del<<endl;
    OutQueue(q,del);
    cout<<"pop "<<del<<endl;
    OutQueue(q,del);
    cout<<"pop "<<del<<endl;
    if(!OutQueue(q,del))
    {
        cout<<"pop default"<<endl;
    }
    return 0;
}

