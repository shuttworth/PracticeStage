#include <iostream>

using std::cout;
using std::endl;

class queue
{
private:
    int * _array;
    int _size;
    int _head;
    int _tail;
public:
    queue(int size)
        :_array(new int [size]())
         ,_size(size)
         ,_head(0)
         ,_tail(0)
    { }

    bool empty() const
    {
        return _head==_tail;
    }
    bool full() const
    {
        return _head==(_tail+1)%_size;
    }

    void push(int number)
    {
        if(!full())
        {
            _array[_tail++]=number;
            _tail%=_size;//经常取模
            cout<<"void push(int number)"<<endl;
        }
        else 
        {
            cout<<"队列已满"<<endl;
        }
    }

    void pop()
    {
        if(!empty())
        {
           // _array[_head++]=    不用管这个元素的东西，直接移动头指针即可
           ++_head;
           _head%=_size;
        }else
        {
            cout<<"队列已空"<<endl;
        }
    }
    
    int front()
    {
        cout<<_array[_head]<<endl;
        return 0;
    }

    int back()
    {
        cout<<_array[(_tail-1+_size)%_size]<<endl;
        return 0;
    }

};

int main(void )
{
    queue que1(10);
    que1.push(3);
    que1.push(6);
    que1.push(9);
    que1.push(2);
    que1.push(4);
    que1.push(6);
    que1.push(8);
    que1.push(10);
    que1.front();
    que1.back();
    que1.pop();
    que1.front();
    que1.back();
    que1.pop();
    que1.front();
    que1.back();
    que1.pop();
    que1.front();
    que1.back();

}
