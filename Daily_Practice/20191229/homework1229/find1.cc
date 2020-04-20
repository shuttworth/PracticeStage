#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

void test0(){ //未充分利用到有序这个条件
    int a[5]={1,3,5,8,10};
    int b[7]={2,4,6,8,10,12,14};
    int * c=new int[11]();
    int i,j;
   // cout<<c[0]<<endl; 测试
   //cout<<i<<endl;
   int La=sizeof(a)/sizeof(int);
    int Lb=sizeof(b)/sizeof(int);
    for(i=0;i<La;i++)
    {
       int  k=a[i];
       if( (++c[k])>1)
       {
           cout<<a[i];
       }
    }
    for(j=0;j<Lb;j++)
    {
       int  k=b[j];
        if((++c[k])>1)
        {
            cout<<b[j]<<"  ";
        }
    }

    cout<<endl;
}

void test1()
{
    int a[5]={1,3,5,8,10};
    int b[7]={2,4,6,8,10,12,14};
    for(int i=0,j=0;i<5&&j<7;)
    {
        if(a[i]<b[j])
        {
            i++;
        }else if(a[i]==b[j])
        {
            cout<<a[i]<<" ";
            i++,j++;
        }
        else
       // else if(a[i]>b[j]) 
        {
            j++;
        } 
    }
    cout<<endl;
}

int main()
{
   // test0();
   test1();
    return 0;
}

