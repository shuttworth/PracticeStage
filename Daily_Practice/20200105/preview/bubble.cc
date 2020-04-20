#include <iostream>
using namespace std;

int main()
{
    int a[10]={3,1,4,2,5};
    int i=0,j=0,temp; //这句省去，int放在for里面写
    for(i=0;i<=4;i++) // i=0 需要一直写
    {
        for(j=0;j<5-i;j++) //同j=0；j<5-i
        {
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

    for(i=0;i<=4;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}

