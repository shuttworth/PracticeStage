#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;
#define Maxsize 100

typedef int ElemType; //直接用int我觉着也可以

typedef struct {
    ElemType data[Maxsize];
    int length;
}Sqlist;

typedef struct //动态分配
{
    ElemType * data;
    int capacity;
    int length;
}SeqList;

bool ListInsert(Sqlist &L,int i,ElemType e)
{
    if(i<1||i>L.length+1||L.length>=Maxsize)
    {
        return false;
    }
    for(int j=L.length;j>=i;j--)
    {
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}


bool ListDelete(Sqlist &L,int i,ElemType &e)
{
    if(i<1||i>L.length)
    {
        return false;
    }
    e=L.data[i-1]; //获取顺序表中对应的元素，赋值给e,得到要删除的那个值
    for(int j=i;j<L.length;j++)
    {
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}

void LocateFind(Sqlist l,ElemType e)
{
    for(int idx=0;idx<l.length;idx++)
    {
        if(l.data[idx]==e)
        {
            cout<<"Locate of "<<e<<" is "<<idx<<endl;
            return;
        }
    }
}

void print(Sqlist l)
{
    for(int idx=0;idx<l.length;idx++)
    {
        cout<<l.data[idx]<<"  ";
    }
    cout<<endl;
}

int main()
{
    Sqlist l;
    l.data[0]=1;
    l.data[1]=3;
    l.data[2]=5;
    l.data[3]=7;
    l.data[4]=9;
    l.length=5;
    int ret=ListInsert(l,2,2);
    if(ret)
    {
        cout<<"插入成功"<<endl;
    }else cout<<"插入失败"<<endl;
    print(l);
    
    ElemType del;
    LocateFind(l,7);
    ret=ListDelete(l,3,del);
    if(ret)
    {
        cout<<"delete success"<<endl;
    }else cout<<"delete default"<<endl;

    cout<<"del="<<del<<endl;
    print(l);
    return 0;
}

