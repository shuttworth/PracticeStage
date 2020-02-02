#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;
//头插法新建链表
LinkList CreatList1(LinkList &L)
{
	LNode *s;int x;
	L=(LinkList)malloc(sizeof(LNode));//带头节点的链表
	L->next=NULL;
	scanf("%d",&x);
	while(x!=9999){
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		s->next=L->next;
		L->next=s;
		scanf("%d",&x);
	}
	return L;
}
//尾插法新建链表
LinkList CreatList2(LinkList &L)
{
	int x;
	L=(LinkList)malloc(sizeof(LNode));//带头节点的链表
	LNode *s,*r=L;
	scanf("%d",&x);
	while(x!=9999){
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		r->next=s;
		r=s;//r指向新的表尾结点
		scanf("%d",&x);
	}
	r->next=NULL;
	return L;
}
//按序号查找结点值
LNode *GetElem(LinkList L,int i)
{
	int j=1;
	LNode *p=L->next;
	if(i==0)
		return L;
	if(i<1)
		return NULL;
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	return p;
}
//按值查找
LNode *LocateElem(LinkList L,ElemType e)
{
	LNode *p=L->next;
	while(p!=NULL&&p->data!=e)
		p=p->next;
	return p;
}
//新结点插入第i个位置
bool ListFrontInsert(LinkList L,int i,ElemType e)
{
	LinkList p=GetElem(L,i-1);
	if(NULL==p)
	{
		return false;
	}
	LinkList s=(LNode*)malloc(sizeof(LNode));//为新插入的结点申请空间
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}
//删除第i个结点
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
//打印链表中每个结点的值
void PrintList(LinkList L)
{
	L=L->next;
	while(L!=NULL)
	{
		printf("%3d",L->data);
		L=L->next;
	}
	printf("\n");
}
int main()
{
	LinkList L;
	LinkList search;
	//CreatList1(L);//输入数据可以为3 4 5 6 7 9999
	CreatList2(L);//输入数据可以为3 4 5 6 7 9999
	PrintList(L);
	search=GetElem(L,2);
	if(search!=NULL)
	{
		printf("按序号查找成功\n");
		printf("%d\n",search->data);
	}
	search=LocateElem(L,6);
	if(search!=NULL)
	{
		printf("按值查找成功\n");
		printf("%d\n",search->data);
	}
	ListFrontInsert(L,2,99);
	PrintList(L);
	ListDelete(L,4);
	PrintList(L);
	system("pause");
}