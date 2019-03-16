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

    bool empty() const 
    {
        return _top==-1;
    }

    bool full() const
    {
        return _top==_size-1;
    }

    int top() 
    {
        if(!empty())
        {
            return _array[_top];
        }
        cout<<"堆已空"<<endl;
        return 0;
    }

    void push(int number)
    {
        if(!full())
        {
            _array[++_top]=number;
            cout <<"void push(int number)"<<endl;
        }
        else cout<<"堆已满"<<endl;
    }

    void pop()
    {
        if(!empty())
        {
            --_top;
            cout<<"void pop()"<<endl;
        }else cout<<"堆已空"<<endl;

    }


    ~stack()
    {
        delete [] _array;
        cout <<"~stack()"<<endl;
    }
};

int main(void)
{
    stack sta1(10);
    cout <<"栈顶元素是"<<sta1.top()<<endl;
    sta1.push(3);
    cout <<"栈顶元素是"<<sta1.top()<<endl;
    sta1.push(6);
    cout <<"栈顶元素是"<<sta1.top()<<endl;
    sta1.push(9);
    cout <<"栈顶元素是"<<sta1.top()<<endl;
    sta1.pop();
    cout <<"栈顶元素是"<<sta1.top()<<endl;
    sta1.pop();
    cout <<"栈顶元素是"<<sta1.top()<<endl;

}
