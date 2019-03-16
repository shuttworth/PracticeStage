#include <string.h>
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
        :_array(new int [1]())
         ,_size(size)
         ,_head(0)
         ,_tail(0)
   {}

    bool empty() const
    {
        return _head==_tail;
    }

    bool full() const
    {
        return _head==(_tail+1)%_size;
    }

    int front()
    {
        return _array[_head];
    }

    int back()
    {
        return _array[(_tail-1+_size)%_size];
    }

    void push(int number)
    {
        if(!full())
        {
            _array[++_tail]=number;
            _tail%=_size;
            cout<<"void push(int number)"<<endl;
        }else
        cout<<"队列已满"<<endl;
    }
    
    void pop()
    {
        if(!empty())
        {
            ++_head;
            _head%=_size;
            cout<<"void pop()"<<endl;
        }else
        cout<<"队列已空"<<endl;
    }
};

int main(void)
{
    queue que1(10);
    que1.push(3);
    que1.push(6);
    que1.push(9);
    cout<<"队头元素是"<<que1.front()<<endl;
    cout<<"队尾元素是"<<que1.back()<<endl;
    que1.pop();
    cout<<"队头元素是"<<que1.front()<<endl;
    cout<<"队尾元素是"<<que1.back()<<endl;
    que1.pop();
    cout<<"队头元素是"<<que1.front()<<endl;
    cout<<"队尾元素是"<<que1.back()<<endl;
    que1.pop();
    cout<<"队头元素是"<<que1.front()<<endl;
    cout<<"队尾元素是"<<que1.back()<<endl;
}
