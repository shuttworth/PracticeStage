#include <iostream>

using std::cout;
using std::endl;

class stack
{
private:
    int _size;
    int _top;
    int * _array;

public:
    stack(int size)
    :_size(size)
     ,_top(-1)
     ,_array(new int[1]())
    {}


    bool empty() const //为何加const
    {
        return _top==-1;
    }

    bool full() const
    {
        return _top==_size-1;
    }

    void push(int number) 
    {
        if(!full())
        {
            _array[++_top]=number; //注意，自己写的时候错在++_top
        }
        else       cout<<"already full"<<endl;
    }

    void pop()
    {
        if(!empty())
        {
            --_top;
        }
        else    cout<<"already empty"<<endl;
    }

    int top()
    {
        return _array[_top];
    }

};


int main()
{
    stack st1(5);
    st1.push(10);
   // cout<<st1.top()<<endl;
    st1.push(12);
   // cout<<st1.top()<<endl;
    st1.push(14);
    cout<<st1.top()<<endl;
    st1.pop();
    cout<<st1.top()<<endl;

    return 0;
}

