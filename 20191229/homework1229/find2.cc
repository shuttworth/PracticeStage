#include <iostream>
#include <string.h>
#include <stdlib.h>
using std::cout;
using std::endl;

void test0(){
    int a[5]={1,3,5,8,10};
    int b[7]={2,4,6,8,10,12,14};
    // int k[6]={1,3,5,8,10,11};
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
    int c[6]={1,3,5,8,10,11};

    int i=0,j=0,k=0;
    if(a[i]==b[j]&&b[j]==c[k])
    {
        cout<<a[i]<<"  ";
        i++,j++,k++;
    }

    if(a[i]<b[j]&&b[j]<=c[k])
    {

    }
}



void find1in2(int a[],int b[])
{
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

void compare1vsn(int a,int *c)
{
    int Lc=sizeof(c)/sizeof(int);
   /* if(a<c[0])
    {
        exit(1);
    }*/
    for(int i=0;i<Lc;)
    {
        if(c[i]==a)
        {
            cout<<a;
        }
        i++;
    }
}

int main()
{

    int a[5]={1,3,5,8,10};
    int b[7]={2,4,6,8,10,12,14};
    int c[4]={2,8,10,12};
    int m;

    for(int i=0,j=0;i<5&&j<7;)
    {
        if(a[i]<b[j])
        {
            i++;
        }else if(a[i]==b[j])
        {
            m=a[i];
            compare1vsn(m,c); //后面调用c的时候，数字位置指针应该有所偏移,那个跳出exit也可以执行
            // cout<<a[i]<<" ";
            i++,j++;
        }
        else
            // else if(a[i]>b[j]) 
        {
            j++;
        } 
    }

    cout<<"over"<<endl;
    return 0;
}
