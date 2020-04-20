#include <iostream>

using std::cout;
using std::endl;

class queue
{
public:
    queue(int size)
        :_array(new int [size]())
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
        return _head==((_tail+1)%_size);
    }
    
    int front()
    {
        return _array[_head];
    }

    int back()
    {
        return _array[(_tail-1+_size)%_size]; //第一个格子的值是0
    }

    void push(int number)
    {
        if(!full())
        {
            _array[_tail++]=number;
            _tail%=_size;
            cout <<"void push(int number)"<<endl;
        }else
        {
            cout << "队列已满" <<endl;
        }
    }

    void pop()
    {
        if(!empty())
        {
            ++_head;
            _head%=_size;
            cout <<"void pop()"<<endl;
        }else
        {
            cout <<"队列已空"<<endl;
        }
    }

private:
    int* _array;
    int _size;
    int _head;
    int _tail;
};


int main()
{
    queue que1(10);
    que1.push(3);
    que1.push(6);
   cout<<"front=="<< que1.front()<<endl;
   cout<<"back=="<< que1.back()<<endl;

    que1.push(9);
   cout<<"front=="<< que1.front()<<endl;
   cout<<"back=="<< que1.back()<<endl;
    
    que1.pop();
   cout<<"front=="<< que1.front()<<endl;
   cout<<"back=="<< que1.back()<<endl;
    
    return 0;

}
