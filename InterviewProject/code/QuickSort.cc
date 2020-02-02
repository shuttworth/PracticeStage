#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

int randomInRange(int start,int end)
{
    srand(time(NULL));

    return start + rand()%(end-start+1);
}

void swap(int * elem1,int * elem2)
{
    int temp=*elem1;
    *elem1=*elem2;
    *elem2=temp;
}

int partition(int data[],int length,int start,int end)
{
    if(data==NULL||length<=0||start<0||end>=length)
    {
        cout<<"Invalid figures"<<endl;
    }

    int index=randomInRange(start,end);
    swap(&data[index],&data[end]);

    int small=start-1;
    for(index=start;index<end;++index)
    {
        if(data[index]<data[end])
        {
            ++small;
            if(small!=index)
            {
                swap(&data[index],&data[end]);
            }
        }
    }
    swap(&data[++small], &data[end]);

    return small;
}

void quickSort(int *data, int len, int start, int end)
{
    if(start == end)
        return;

    int index = partition(data, len, start, end);
    if(index > start)
        quickSort(data, len, start, index - 1);
    if(index < end)
        quickSort(data, len, index + 1, end);
}

void print(int array[])
{
    for(int idx=0;idx<9;idx++)
    {
        cout<<array[idx]<<"  ";
    }
    cout<<endl;
}

int main()
{
    int array[]={5,7,9,11,13,15,2,4,6};
    quickSort(array,9,0,8);
    print(array);
    return 0;
}

