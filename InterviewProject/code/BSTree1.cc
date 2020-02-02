#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;


typedef int KeyType;

typedef struct BSTNode{
    KeyType key;
    struct BSTNode * lchild,* rchild;
}BSTNode,*BiTree;


int BST_Insert(BiTree &T,KeyType k)
{   
        if(NULL==T)
        {
            T=(BiTree)malloc(sizeof(BiTree));
            T->key=k;
            T->lchild=T->rchild=NULL;
            return 1;
        }
        else if(k==T->key)
            return 0;
        else if(k<T->key)
            return BST_Insert(T->lchild,k);
        else 
            return BST_Insert(T->rchild,k);
}


void Creat_BST(BiTree &T,KeyType str[],int n)
{
    T=NULL;
    int i=0;
    while(i<n)
    {
        BST_Insert(T,str[i]);
        i++;
    }

}

void InOrder(BiTree T)
{
    if(T!=NULL)
    {
        InOrder(T->lchild);
        cout<<T->key<<"  ";
        InOrder(T->rchild);
    }
    //cout<<endl;
}


int main()
{   
    BiTree T;
 //   BiTree Parent;
   // BiTree search;
    KeyType str[]={24,56,78,97,43,32,11};
    cout<<"str[]={24,56,78,97,43,32,11}"<<endl;
    Creat_BST(T,str,7);
    InOrder(T);
    cout<<endl;

    return 0;
}

