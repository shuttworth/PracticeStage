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

    void printhead()
    {
        cout<<_array[_top]<<endl;
    }

};


int main()
{
    stack st1(5);
    st1.push(1);
    st1.printhead();
    st1.push(2);
    st1.printhead();
    st1.push(3);
    st1.printhead();
    st1.push(4);
    st1.printhead();
    st1.push(5);
    st1.printhead();
    st1.pop();
    st1.printhead();
    st1.pop();

    st1.printhead();
    return 0;
}

