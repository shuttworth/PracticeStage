#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

#define Maxsize 50
typedef int ElemType;

typedef struct
{
    ElemType data[Maxsize];
    int top;
}Sqstack;

void InitStack(Sqstack &s)
{
    s.top=-1;
}

bool StackEmpty(Sqstack &s)
{
    return s.top==-1;
}

bool StackFull(Sqstack &s)
{
    return s.top==Maxsize-1;
}

bool push(Sqstack &s,ElemType x)
{
    if(!StackFull(s))
    {
        s.data[s.top++]=x;
        return true;
    }else return false;
}

bool pop(Sqstack &s,ElemType &del)
{
    if(!StackEmpty(s))
    {
        del=s.data[s.top--];
        return true;
    }
    return false;
}

bool GetTop(Sqstack &s,ElemType &e)
{
    if(StackEmpty(s))
    {
        return false;
    }
    e=s.top;
    return true;
}


int main()
{
    Sqstack sq1;
    ElemType top;
    ElemType del;
    InitStack(sq1);
    push(sq1,2);
    cout<<"push 2"<<endl;
    if(GetTop(sq1,top)) cout<<"top= "<<top<<endl;
    push(sq1,4);
    cout<<"push 4"<<endl;
    if(GetTop(sq1,top)) cout<<"top= "<<top<<endl;
    push(sq1,6);
    cout<<"push 6"<<endl;
    if(GetTop(sq1,top)) cout<<"top= "<<top<<endl;
    push(sq1,8);
    cout<<"push 8"<<endl;
    if(GetTop(sq1,top)) cout<<"top= "<<top<<endl;
    
    pop(sq1,del);
    cout<<"pop "<<del<<endl;
    if(GetTop(sq1,top)) cout<<"top= "<<top<<endl;
    pop(sq1,del);
    cout<<"pop "<<del<<endl;
    if(GetTop(sq1,top)) cout<<"top= "<<top<<endl;
    return 0;
}

