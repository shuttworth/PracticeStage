#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

//与一般写法的区别就是，把int 等具体类型用T来代替

template<typename T,typename Compare = std::less<T>>
class HeapSort
{
public:
    HeapSort(const vector <T> & data)
        :_data(data)
    {
        cout<<"size = "<<_data.size()<<endl;
    }

    //分堆
    void heapAdjust(int parent,int size)
    {
        //构造大顶堆
        //堆的性质，0 1 2 3 4 5等等，序号有关系
        int left= 2 * parent +1;
        while(left<size)
        {
            if(left+1<size && _data[left] < _data[left+1]) //如果没越界并且左边小于右边
            {
                ++left;
            }

            if(_data[parent]<_data[left])
            {
                std::swap(_data[parent],_data[left]);
                parent=left;
                left=2*parent+1;
            }else
                break;
        }
    }

    void sort()
    {
        int size=_data.size();
        for(int idx=size/2-1;idx>=0;--idx)
        {
            heapAdjust(idx,size);
        }

        for(;size>0;--size){
            std::swap(_data[0],_data[size-1]);
            heapAdjust(0,size-1);
        }

    }

    void display() const
    {
        auto rit=_data.rbegin();
        for(;rit!=_data.rend();++rit)
        {
            cout<<*rit<<"  ";
        }
        cout<<endl;
    }

private:
    vector<T> _data;
};


int main()
{
    vector<int>numbers{4,2,5,3,1,6,7};
    HeapSort<int> hs(numbers);
    hs.sort();
    hs.display();
    return 0;
}

