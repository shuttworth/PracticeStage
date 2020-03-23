#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
//��̬����
typedef struct{
	ElemType data[MaxSize];
	int length;
}SqList;
//��̬����
#define InitSize 100
typedef struct{
	ElemType *data;
	int capacity;//��̬������������
	int length;
}SeqList;
//i���������λ�ã���1��ʼ
bool ListInsert(SqList &L,int i,ElemType e)
{
	if(i<1||i>L.length+1)//�ж�Ҫ�����λ���Ƿ�Ϸ�
		return false;
	if(L.length>=MaxSize)
		return false;
	for(int j=L.length;j>=i;j--)//�ƶ�˳����е�Ԫ��
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;//�����±���㿪ʼ�������һ��λ�ã����ʵ��±�Ϊ0
	L.length++;
	return true;
}
//ɾ��ʹ��Ԫ��e�����õ�Ŀ�����ó���Ӧ��ֵ
bool ListDelete(SqList &L,int i,ElemType &e)
{
	if(i<1||i>L.length)//���ɾ����λ���ǲ��Ϸ�
		return false;
	e=L.data[i-1];//��ȡ˳����ж�Ӧ��Ԫ�أ���ֵ��e
	for(int j=i;j<L.length;j++)
		L.data[j-1]=L.data[j];
	L.length--;//ɾ��һ��Ԫ�أ�˳������ȼ�1
	return true;
}
//���ҳɹ�������λ�ã�λ�ô�1��ʼ������ʧ�ܣ�����0
int LocateElem(SqList L,ElemType e)
{
	int i;
	for(i=0;i<L.length;i++)
		if(L.data[i]==e)
			return i+1;//��1����Ԫ����˳����е�λ��
	return 0;
}
//��ӡ˳���Ԫ��
void PrintList(SqList &L)
{
	for(int i=0;i<L.length;i++)
	{
		printf("%4d",L.data[i]);
	}
	printf("\n");
}
int main()
{
	SqList L;//˳���������
	bool ret;//�鿴����ֵ
	ElemType del;//Ҫɾ����Ԫ��
	//�����ֶ���˳����и�ֵ
	L.data[0]=1;
	L.data[1]=2;
	L.data[2]=3;
	L.length=3;//�ܼ�����Ԫ��
	ret=ListInsert(L,2,60);
	if(ret)
	{
		printf("����ɹ�\n");
		PrintList(L);
	}else{
		printf("����ʧ��\n");
	}
	ret=ListDelete(L,1,del);
	if(ret)
	{
		printf("ɾ���ɹ�\n");
		printf("ɾ��Ԫ��ֵΪ %d\n",del);
		PrintList(L);
	}else{
		printf("ɾ��ʧ��\n");
	}
	ret=LocateElem(L,60);
	if(ret)
	{
		printf("���ҳɹ�\n");
		printf("Ԫ��λ��Ϊ %d\n",ret);
	}else{
		printf("����ʧ��\n");
	}
	system("pause");//ͣ�ڿ���̨����
}
