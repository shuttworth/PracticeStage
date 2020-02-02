#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

//typedef int Elemtype;

typedef struct Lnode
{
    int data;
    struct Lnode * next;
}LNode,*LinkList;

LinkList CreateList1(LinkList &L) //传指针进来
{
    LNode *s;
    int x;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;//L是地址
    scanf("%d",&x);
    while(x<100)
    {
        s=(LinkList)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;//头插法
        scanf("%d",&x);
    }
    return L;
}


LinkList CreateList2(LinkList &L)
{
    int x;
    L=(LinkList)malloc(sizeof(LNode));
    LNode *s,*r=L;
    scanf("%d",&x);
    while(x<100)
    {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        r->next=s; //尾插法
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;
    return L;
}

//按序号查找结点值
LNode * GetElem(LinkList L,int i)
{
    int j=1;//计数
    LinkList p=L->next;//
    if(i==0) return L;
    if(i<1) return NULL;// 进行到这一步，说明已经排除了0的情况 
    if(p&&j<i)  //p非空而且j<i
    {
        p=p->next;
        j++;
    }
    return p;
}

//按值查找
LinkList LocateElem(LinkList L,int e)
{
    LNode *p=L->next;//L相当于头结点，L->next是第一个有值的结点所在的位置
    while(p!=NULL&&p->data!=e)
    {
        p=p->next;
    }
    return p;
}

//新节点插入第i个位置
bool ListInsert(LinkList L,int i,int e)
{
    LinkList p=GetElem(L,i-1);
    if(NULL==p)
    {
        return false;
    }
    LinkList s=(LNode*)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;//先保证p->next的值不丢失
    p->next=s;
    return true;
}


bool ListDelete(LinkList L,int i)
{
    LinkList p=GetElem(L,i-1);
    if(NULL==p)
    {
        return false;
    }
    LinkList q;
    q=p->next;
    p->next=q->next;
    free(q);
    return true;
}

void printList(LinkList L)
{
    L=L->next;
    while(L!=NULL)
    {
        cout<<L->data<<"  ";
        L=L->next;
    }
    cout<<endl;
}



int main()
{
    LinkList L;
    CreateList2(L);
    printList(L);

    LinkList ret=GetElem(L,2);
    cout<<"GetElem(L,2) is "<<ret->data<<endl;   
    return 0;
}

