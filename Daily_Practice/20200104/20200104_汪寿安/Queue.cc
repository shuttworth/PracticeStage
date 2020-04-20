#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class queue
{
    private:
        int *_array;
        int _size;
        int _head;
        int _tail;

    public:
        queue(int size)
        :_array(new int[1]())
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
                _array[++_tail]=number;
            }
            else cout<<"already full"<<endl;
        }

        void pop()
        {
            if(!empty())
            {
                ++_head;
            }
            else cout<<"already empty"<<endl;
        }

        int front()
        {
            return _array[_head];
        }

        int back()
        {
            return _array[_tail];
        }



};

int main()
{
    queue qu1(8);
    qu1.pop();
    qu1.push(1);
    qu1.push(2);
    cout<<qu1.front()<<endl;
    cout<<qu1.back()<<endl;
    qu1.pop();
    cout<<qu1.front()<<endl;
    cout<<qu1.back()<<endl;
    qu1.push(3);
    cout<<qu1.front()<<endl;
    cout<<qu1.back()<<endl;

    return 0;
}

