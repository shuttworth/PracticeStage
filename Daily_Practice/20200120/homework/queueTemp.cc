#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template <class T>
class queue
{
public:
    queue(int size)
        :_array(new T [size]())
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
    
    T front()
    {
        return _array[_head];
    }

    T back()
    {
        return _array[(_tail-1+_size)%_size]; //第一个格子的值是0
    }

    void push(T number)
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

    ~queue()
    {
        if(_array){
            delete [] _array;
            
        }
    }

private:
    T* _array;
    int _size;
    int _head;
    int _tail;
};


void test0()
{

    queue<int> que1(10);
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
    
}

void test1()
{

    queue<string> que1(10);
    que1.push("hello");
    que1.push("world");
   cout<<"front=="<< que1.front()<<endl;
   cout<<"back=="<< que1.back()<<endl;

    que1.push("lu an");
   cout<<"front=="<< que1.front()<<endl;
   cout<<"back=="<< que1.back()<<endl;
    
    que1.pop();
   cout<<"front=="<< que1.front()<<endl;
   cout<<"back=="<< que1.back()<<endl;
}


int main()
{
    test0();
    test1();
    return 0;
}
