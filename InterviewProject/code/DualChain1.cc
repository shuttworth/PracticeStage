#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

typedef int Elemtype;
typedef struct DNode
{
    Elemtype data;
    struct DNode * prior,*next;
}DNode,*DLinkList;

//双线链表头插法,头插法每次都插在初始化列表的头结点后面，其他元素之前
DLinkList Dlist_head_Create(DLinkList &DL)
{
    DNode *s;int x;
    DL=(DLinkList)malloc(sizeof(DNode));
    DL->next=NULL;
    DL->prior=NULL;
    scanf("%d",&x);
    while(x<100)
    {
        s=(DLinkList)malloc(sizeof(DNode));
        s->data=x;
        s->next=DL->next;//(1)
        if(DL->next!=NULL)
        {
            DL->next->prior=s;//(2)这两步一定要放在前面，以防DL->next这个元素丢了
        }
        s->prior=DL;
        DL->next=s;
        scanf("%d",&x);
    }
    return DL;
}

DLinkList Dlist_tail_Create(DLinkList &DL)
{
    DL=(DLinkList)malloc(sizeof(DNode));
    DNode *s,*r=DL;
    int x;
    DL->next=NULL;
    DL->prior=NULL;
    scanf("%d",&x);
    while(x<100)
    {
        s=(DLinkList)malloc(sizeof(DNode));
        s->data=x;
        r->next=s;
        s->prior=r;
        r=s;//r指向新的表尾结点
        scanf("%d",&x);
    }
    return DL;
}

//按序号查找结点值,返回值为该序号处的结点地址
DLinkList GetElem(DLinkList DL,int i)
{
    int j=1;
    DNode *p=DL->next;
    if(i==0) return DL;
    if(i<1) return NULL;
    if(p&&j<i)
    {
        p=p->next;
        j++;
    }
    return p;
}

//新结点插入第i个位置
bool ListInsert(DLinkList DL,int i,Elemtype e)
{
    DLinkList p=GetElem(DL,i-1); //得到插入位置前一个的地址
    if(NULL==p)
    {
        return false;
    }
    DLinkList q=(DLinkList)malloc(sizeof(DNode));
    q->data=e;
    q->next=p->next;
    p->next->prior=q;
    p->next=q;
    q->prior=p;
    return true;
}

bool ListDelete(DLinkList DL,int i)
{
    DLinkList p=GetElem(DL,i-1); //得到插入位置前一个的地址
    if(NULL==p)
    {
        return false;
    }
    DLinkList q;
    q=p->next;
    if(NULL==q)
    {return false;}
    p->next=q->next;
    if(q->next!=NULL)
    {
        q->next->prior=p;
    }
    free(q);
    return true;
}



void printList(DLinkList DL)
{
    DL=DL->next;
    while(DL!=NULL)
    {
        cout<<DL->data<<"  ";
        DL=DL->next;
    }
    cout<<endl;
}


int main()
{
    DLinkList l;
    Dlist_tail_Create(l);
    printList(l);
    ListInsert(l,3,5);
    cout<<"ListInsert(l,3,5)"<<endl;
    printList(l);
    ListDelete(l,5);
    cout<<"ListDelete(l,5)"<<endl;
    printList(l);
    return 0;
}

